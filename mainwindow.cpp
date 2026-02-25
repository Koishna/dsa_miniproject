#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "travelmanager.h"

TravelManager manager;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->tripTable->setColumnCount(3);
    QStringList headers;
    headers << "Source" << "Destination" << "Budget";
    ui->tripTable->setHorizontalHeaderLabels(headers);

    auto refreshRouteTable = [=]() {
        ui->tripTable->setRowCount(0);
        auto routes = manager.getRoutes();
        for (const auto &r : routes) {
            int row = ui->tripTable->rowCount();
            ui->tripTable->insertRow(row);
            ui->tripTable->setItem(row,0,new QTableWidgetItem(std::get<0>(r)));
            ui->tripTable->setItem(row,1,new QTableWidgetItem(std::get<1>(r)));
            ui->tripTable->setItem(row,2,new QTableWidgetItem(QString::number(std::get<2>(r))));
        }
    };

    auto refreshTripLog = [=]() {
        ui->tripLog->clear();
        auto trips = manager.getTripQueue();
        for (const auto &t : trips) {
            ui->tripLog->append(std::get<0>(t) + " -> " + std::get<1>(t) +
                                " (Budget: " + QString::number(std::get<2>(t)) + ")");
        }
    };

    connect(ui->addCityButton, &QPushButton::clicked, this, [=](){
        QString cityName = ui->cityNameInput->text().trimmed();
        QString id = manager.addCity(cityName);

        if (!id.isEmpty()) {
            ui->statusLabel->setText("City added: " + cityName + " (" + id + ")");
            ui->srcDropdown->addItem(cityName);
            ui->destDropdown->addItem(cityName);
            ui->cityNameInput->clear();
        } else {
            ui->statusLabel->setText("Duplicate or invalid city!");
        }
    });

    connect(ui->addRouteButton, &QPushButton::clicked, this, [=](){
        QString src = ui->srcDropdown->currentText();
        QString dest = ui->destDropdown->currentText();
        int budget = ui->budgetInput->text().toInt();

        if (manager.addRoute(src, dest, budget)) {
            ui->statusLabel->setText("Route added!");
            refreshRouteTable();
            ui->budgetInput->clear();
        } else {
            ui->statusLabel->setText("Duplicate or invalid route!");
        }
    });

    connect(ui->addTripButton, &QPushButton::clicked, this, [=](){
        QString src = ui->srcDropdown->currentText();
        QString dest = ui->destDropdown->currentText();
        int budget = ui->budgetInput->text().toInt();

        manager.enqueueTrip(src, dest, budget);
        ui->statusLabel->setText("Trip enqueued: " + src + " -> " + dest);
        refreshTripLog();
    });

    connect(ui->dequeueButton, &QPushButton::clicked, this, [=](){
        manager.dequeueTrip();
        ui->statusLabel->setText("Trip dequeued.");
        refreshTripLog();
    });

    connect(ui->undoButton, &QPushButton::clicked, this, [=](){
        manager.undoLastAction();
        ui->statusLabel->setText("Undo performed.");
        refreshRouteTable();
        refreshTripLog();
    });

    connect(ui->mstButton, &QPushButton::clicked, this, [=](){
        QString start = ui->srcDropdown->currentText();
        QString mst = manager.minimumSpanningTree(start);
        ui->pathDisplay->setText(mst);
    });

    connect(ui->searchButton, &QPushButton::clicked, this, [=](){
        QString cityName = ui->cityNameInput->text().trimmed();
        if (manager.searchCity(cityName)) {
            ui->statusLabel->setText("City found: " + cityName);
        } else {
            ui->statusLabel->setText("City not found!");
        }
    });
}

MainWindow::~MainWindow() {
    delete ui;
}
