/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
  QTabWidget *tabWidget;
  QWidget *tab;
  QHBoxLayout *horizontalLayout_5;
  QHBoxLayout *horizontalLayout_4;
  QLabel *label;
  QComboBox *comboBox;
  QHBoxLayout *horizontalLayout;
  QLabel *label_2;
  QSpinBox *spinBox;
  QPushButton *colorBtn;
  QPushButton *genBtn;
  QLabel *label_3;
  QWidget *tab_2;
  QHBoxLayout *horizontalLayout_3;
  QHBoxLayout *horizontalLayout_2;
  QPushButton *loadBtn;
  QPushButton *oriBtn;
  QPushButton *triBtn;
  QPushButton *saveBtn;
  QLabel *label_4;

  void setupUi(QWidget *Widget)
  {
    if (Widget->objectName().isEmpty())
      Widget->setObjectName(QString::fromUtf8("Widget"));
    Widget->resize(586, 300);
    tabWidget = new QTabWidget(Widget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 30, 669, 120));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    horizontalLayout_5 = new QHBoxLayout(tab);
    horizontalLayout_5->setSpacing(6);
    horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
    horizontalLayout_4 = new QHBoxLayout();
    horizontalLayout_4->setSpacing(6);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    label = new QLabel(tab);
    label->setObjectName(QString::fromUtf8("label"));
    label->setLayoutDirection(Qt::LeftToRight);
    label->setStyleSheet(QString::fromUtf8("margin:right;"));

    horizontalLayout_4->addWidget(label);

    comboBox = new QComboBox(tab);
    comboBox->addItem(QString());
    comboBox->addItem(QString());
    comboBox->addItem(QString());
    comboBox->addItem(QString());
    comboBox->setObjectName(QString::fromUtf8("comboBox"));

    horizontalLayout_4->addWidget(comboBox);

    horizontalLayout_5->addLayout(horizontalLayout_4);

    horizontalLayout = new QHBoxLayout();
    horizontalLayout->setSpacing(6);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    label_2 = new QLabel(tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setStyleSheet(QString::fromUtf8("margin:right;"));

    horizontalLayout->addWidget(label_2);

    spinBox = new QSpinBox(tab);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));

    horizontalLayout->addWidget(spinBox);

    horizontalLayout_5->addLayout(horizontalLayout);

    colorBtn = new QPushButton(tab);
    colorBtn->setObjectName(QString::fromUtf8("colorBtn"));

    horizontalLayout_5->addWidget(colorBtn);

    genBtn = new QPushButton(tab);
    genBtn->setObjectName(QString::fromUtf8("genBtn"));

    horizontalLayout_5->addWidget(genBtn);

    label_3 = new QLabel(tab);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setStyleSheet(QString::fromUtf8("\n"
                                             "margin:right;\n"
                                             "\n"
                                             "font: 75 16pt \"Adobe Arabic\";\n"
                                             "font-color:red;"));

    horizontalLayout_5->addWidget(label_3);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    horizontalLayout_3 = new QHBoxLayout(tab_2);
    horizontalLayout_3->setSpacing(6);
    horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setSpacing(6);
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    loadBtn = new QPushButton(tab_2);
    loadBtn->setObjectName(QString::fromUtf8("loadBtn"));

    horizontalLayout_2->addWidget(loadBtn);

    oriBtn = new QPushButton(tab_2);
    oriBtn->setObjectName(QString::fromUtf8("oriBtn"));

    horizontalLayout_2->addWidget(oriBtn);

    triBtn = new QPushButton(tab_2);
    triBtn->setObjectName(QString::fromUtf8("triBtn"));

    horizontalLayout_2->addWidget(triBtn);

    saveBtn = new QPushButton(tab_2);
    saveBtn->setObjectName(QString::fromUtf8("saveBtn"));

    horizontalLayout_2->addWidget(saveBtn);

    label_4 = new QLabel(tab_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setStyleSheet(QString::fromUtf8("margin:right;\n"
                                             "\n"
                                             "font: 75 16pt \"Adobe Arabic\";\n"
                                             "font-color:red;"));

    horizontalLayout_2->addWidget(label_4);

    horizontalLayout_3->addLayout(horizontalLayout_2);

    tabWidget->addTab(tab_2, QString());

    retranslateUi(Widget);

    tabWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(Widget);
  } // setupUi

  void retranslateUi(QWidget *Widget)
  {
    Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
    label->setText(QApplication::translate("Widget", "\347\273\230\345\210\266\357\274\232", nullptr));
    comboBox->setItemText(0, QApplication::translate("Widget", "\347\246\273\346\225\243\347\202\271", nullptr));
    comboBox->setItemText(1, QApplication::translate("Widget", "\345\207\270\345\214\205", nullptr));
    comboBox->setItemText(2, QApplication::translate("Widget", "\345\207\270\345\214\205\345\210\207\345\210\206", nullptr));
    comboBox->setItemText(3, QApplication::translate("Widget", "Delaunay\344\270\211\350\247\222\345\275\242", nullptr));

    label_2->setText(QApplication::translate("Widget", "\347\202\271\346\225\260\357\274\232", nullptr));
    colorBtn->setText(QApplication::translate("Widget", "\347\224\237\346\210\220\350\211\262\345\275\251", nullptr));
    genBtn->setText(QApplication::translate("Widget", "\351\207\215\347\275\256", nullptr));
    label_3->setText(QApplication::translate("Widget", "Author: WK", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\346\274\224\347\244\272", nullptr));
    loadBtn->setText(QApplication::translate("Widget", "\345\257\274\345\205\245\345\233\276\347\211\207", nullptr));
    oriBtn->setText(QApplication::translate("Widget", "\345\216\237\345\233\276", nullptr));
    triBtn->setText(QApplication::translate("Widget", "\344\270\211\350\247\222\345\214\226", nullptr));
    saveBtn->setText(QApplication::translate("Widget", "\345\217\246\345\255\230\344\270\272", nullptr));
    label_4->setText(QApplication::translate("Widget", "Author: WK", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\233\276\347\211\207\345\244\204\347\220\206", nullptr));
  } // retranslateUi
};

namespace Ui
{
  class Widget : public Ui_Widget
  {
  };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
