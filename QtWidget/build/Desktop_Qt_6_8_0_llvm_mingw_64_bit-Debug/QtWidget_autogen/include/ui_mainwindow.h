/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *lb_Options;
    QRadioButton *rB_SlcLst;
    QComboBox *cB_Options;
    QRadioButton *rB_BlokPrgBr;
    QProgressBar *pB_10;
    QPushButton *PB_add10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(317, 197);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        lb_Options = new QLabel(groupBox);
        lb_Options->setObjectName("lb_Options");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_Options->sizePolicy().hasHeightForWidth());
        lb_Options->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lb_Options, 0, 1, 1, 1);

        rB_SlcLst = new QRadioButton(groupBox);
        rB_SlcLst->setObjectName("rB_SlcLst");
        rB_SlcLst->setChecked(true);

        gridLayout->addWidget(rB_SlcLst, 1, 0, 1, 1);

        cB_Options = new QComboBox(groupBox);
        cB_Options->addItem(QString());
        cB_Options->addItem(QString());
        cB_Options->addItem(QString());
        cB_Options->addItem(QString());
        cB_Options->addItem(QString());
        cB_Options->setObjectName("cB_Options");

        gridLayout->addWidget(cB_Options, 1, 1, 1, 1);

        rB_BlokPrgBr = new QRadioButton(groupBox);
        rB_BlokPrgBr->setObjectName("rB_BlokPrgBr");
        rB_BlokPrgBr->setChecked(false);

        gridLayout->addWidget(rB_BlokPrgBr, 2, 0, 1, 1);

        pB_10 = new QProgressBar(groupBox);
        pB_10->setObjectName("pB_10");
        pB_10->setValue(24);

        gridLayout->addWidget(pB_10, 3, 0, 1, 1);

        PB_add10 = new QPushButton(groupBox);
        PB_add10->setObjectName("PB_add10");
        PB_add10->setCheckable(true);
        PB_add10->setChecked(false);

        gridLayout->addWidget(PB_add10, 3, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 317, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(rB_SlcLst, &QRadioButton::clicked, cB_Options, qOverload<>(&QComboBox::show));
        QObject::connect(rB_BlokPrgBr, &QRadioButton::clicked, pB_10, qOverload<>(&QProgressBar::show));
        QObject::connect(PB_add10, &QPushButton::clicked, pB_10, qOverload<>(&QProgressBar::update));
        QObject::connect(rB_BlokPrgBr, &QRadioButton::clicked, PB_add10, &QPushButton::setDisabled);
        QObject::connect(rB_SlcLst, &QRadioButton::clicked, PB_add10, &QPushButton::setEnabled);
        QObject::connect(PB_add10, &QPushButton::toggled, pB_10, qOverload<>(&QProgressBar::update));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        lb_Options->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\206\320\270\320\270:", nullptr));
        rB_SlcLst->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\321\200\320\265\321\210\320\270\321\202\321\214 \320\276\320\277\321\206\320\270\320\270", nullptr));
        cB_Options->setItemText(0, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 1", nullptr));
        cB_Options->setItemText(1, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 2", nullptr));
        cB_Options->setItemText(2, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 5", nullptr));
        cB_Options->setItemText(3, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 25%", nullptr));
        cB_Options->setItemText(4, QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 1%", nullptr));

        rB_BlokPrgBr->setText(QCoreApplication::translate("MainWindow", "\320\221\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\265\321\201\321\201", nullptr));
        PB_add10->setText(QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214 \320\275\320\260 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
