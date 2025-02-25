/********************************************************************************
** Form generated from reading UI file 'seconddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDDIALOG_H
#define UI_SECONDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_secondDialog
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *secondDialog)
    {
        if (secondDialog->objectName().isEmpty())
            secondDialog->setObjectName("secondDialog");
        secondDialog->resize(722, 461);
        label = new QLabel(secondDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 0, 251, 101));
        comboBox = new QComboBox(secondDialog);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(70, 320, 111, 25));
        label_2 = new QLabel(secondDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 290, 211, 17));
        label_3 = new QLabel(secondDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(390, 290, 161, 17));
        comboBox_2 = new QComboBox(secondDialog);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(400, 320, 111, 25));
        radioButton = new QRadioButton(secondDialog);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(20, 80, 112, 23));
        radioButton_2 = new QRadioButton(secondDialog);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(150, 80, 112, 23));

        retranslateUi(secondDialog);

        QMetaObject::connectSlotsByName(secondDialog);
    } // setupUi

    void retranslateUi(QDialog *secondDialog)
    {
        secondDialog->setWindowTitle(QCoreApplication::translate("secondDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("secondDialog", "<html><head/><body><p><span style=\" font-weight:700;\">Busca un vuelo</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("secondDialog", "Ciudad de Origen ", nullptr));
        label_3->setText(QCoreApplication::translate("secondDialog", "Ciudad Destino", nullptr));
        radioButton->setText(QCoreApplication::translate("secondDialog", "ida y vuelta", nullptr));
        radioButton_2->setText(QCoreApplication::translate("secondDialog", "Solo ida", nullptr));
    } // retranslateUi

};

namespace Ui {
    class secondDialog: public Ui_secondDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDDIALOG_H
