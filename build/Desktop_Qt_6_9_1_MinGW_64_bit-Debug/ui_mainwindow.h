/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *controlsGroup;
    QFormLayout *formLayout;
    QLabel *cityNameLabel;
    QLineEdit *cityNameInput;
    QLabel *srcLabel;
    QComboBox *srcDropdown;
    QLabel *destLabel;
    QComboBox *destDropdown;
    QLabel *budgetLabel;
    QLineEdit *budgetInput;
    QHBoxLayout *buttonLayout;
    QPushButton *addCityButton;
    QPushButton *addRouteButton;
    QPushButton *addTripButton;
    QPushButton *undoButton;
    QPushButton *dequeueButton;
    QPushButton *mstButton;
    QPushButton *searchButton;
    QTableWidget *tripTable;
    QTextEdit *pathDisplay;
    QTextEdit *tripLog;
    QLabel *statusLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1407, 887);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        controlsGroup = new QGroupBox(centralwidget);
        controlsGroup->setObjectName("controlsGroup");
        formLayout = new QFormLayout(controlsGroup);
        formLayout->setObjectName("formLayout");
        cityNameLabel = new QLabel(controlsGroup);
        cityNameLabel->setObjectName("cityNameLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, cityNameLabel);

        cityNameInput = new QLineEdit(controlsGroup);
        cityNameInput->setObjectName("cityNameInput");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, cityNameInput);

        srcLabel = new QLabel(controlsGroup);
        srcLabel->setObjectName("srcLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, srcLabel);

        srcDropdown = new QComboBox(controlsGroup);
        srcDropdown->setObjectName("srcDropdown");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, srcDropdown);

        destLabel = new QLabel(controlsGroup);
        destLabel->setObjectName("destLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, destLabel);

        destDropdown = new QComboBox(controlsGroup);
        destDropdown->setObjectName("destDropdown");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, destDropdown);

        budgetLabel = new QLabel(controlsGroup);
        budgetLabel->setObjectName("budgetLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, budgetLabel);

        budgetInput = new QLineEdit(controlsGroup);
        budgetInput->setObjectName("budgetInput");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, budgetInput);


        verticalLayout->addWidget(controlsGroup);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addCityButton = new QPushButton(centralwidget);
        addCityButton->setObjectName("addCityButton");

        buttonLayout->addWidget(addCityButton);

        addRouteButton = new QPushButton(centralwidget);
        addRouteButton->setObjectName("addRouteButton");

        buttonLayout->addWidget(addRouteButton);

        addTripButton = new QPushButton(centralwidget);
        addTripButton->setObjectName("addTripButton");

        buttonLayout->addWidget(addTripButton);

        undoButton = new QPushButton(centralwidget);
        undoButton->setObjectName("undoButton");

        buttonLayout->addWidget(undoButton);

        dequeueButton = new QPushButton(centralwidget);
        dequeueButton->setObjectName("dequeueButton");

        buttonLayout->addWidget(dequeueButton);

        mstButton = new QPushButton(centralwidget);
        mstButton->setObjectName("mstButton");

        buttonLayout->addWidget(mstButton);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");

        buttonLayout->addWidget(searchButton);


        verticalLayout->addLayout(buttonLayout);

        tripTable = new QTableWidget(centralwidget);
        if (tripTable->columnCount() < 3)
            tripTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tripTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tripTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tripTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tripTable->setObjectName("tripTable");

        verticalLayout->addWidget(tripTable);

        pathDisplay = new QTextEdit(centralwidget);
        pathDisplay->setObjectName("pathDisplay");

        verticalLayout->addWidget(pathDisplay);

        tripLog = new QTextEdit(centralwidget);
        tripLog->setObjectName("tripLog");

        verticalLayout->addWidget(tripLog);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");

        verticalLayout->addWidget(statusLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        controlsGroup->setTitle(QCoreApplication::translate("MainWindow", "Controls", nullptr));
        cityNameLabel->setText(QCoreApplication::translate("MainWindow", "City Name:", nullptr));
        srcLabel->setText(QCoreApplication::translate("MainWindow", "Source:", nullptr));
        destLabel->setText(QCoreApplication::translate("MainWindow", "Destination:", nullptr));
        budgetLabel->setText(QCoreApplication::translate("MainWindow", "Budget:", nullptr));
        addCityButton->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        addRouteButton->setText(QCoreApplication::translate("MainWindow", "Add Route", nullptr));
        addTripButton->setText(QCoreApplication::translate("MainWindow", "Add Trip", nullptr));
        undoButton->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        dequeueButton->setText(QCoreApplication::translate("MainWindow", "Dequeue", nullptr));
        mstButton->setText(QCoreApplication::translate("MainWindow", "MST", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tripTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Source", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tripTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Destination", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tripTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Budget", nullptr));
        pathDisplay->setPlaceholderText(QCoreApplication::translate("MainWindow", "MST result will be displayed here...", nullptr));
        tripLog->setPlaceholderText(QCoreApplication::translate("MainWindow", "Trip log will show enqueue/dequeue/undo actions...", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status messages will appear here", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
