#include "widget.h"
#include "ui_widget.h"
#include "calculator.h"
#include<QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->maxNum = 10;
    this->coll1 = "";
    this->coll2 = "";
    this->coll = "";
    this->len = 5;
    this->flag = 0;
    this->eq = NULL;
    ui->showPushButton->setEnabled(false);
    memset(this->res, 0, 10 );
    connect(ui->radioButton, &QRadioButton::toggled, [=](){
        this->coll1 = "";
        this->coll2 = "";
        this->coll = "";
        if(ui->radioButton->isChecked()){
            this->coll1.append('+');
        }
        if(ui->radioButton_2->isChecked()){
            this->coll1.append('-');
        }
        if(ui->radioButton_3->isChecked()){
            this->coll2.append('*');
        }
        if(ui->radioButton_4->isChecked()){
            this->coll2.append('/');
        }
    });
    connect(ui->radioButton_2, &QRadioButton::toggled, [=](){
        this->coll1 = "";
        this->coll2 = "";
        this->coll = "";
        if(ui->radioButton->isChecked()){
            this->coll1.append('+');
        }
        if(ui->radioButton_2->isChecked()){
            this->coll1.append('-');
        }
        if(ui->radioButton_3->isChecked()){
            this->coll2.append('*');
        }
        if(ui->radioButton_4->isChecked()){
            this->coll2.append('/');
        }
    });
    connect(ui->radioButton_3, &QRadioButton::toggled, [=](){
        this->coll1 = "";
        this->coll2 = "";
        this->coll = "";
        if(ui->radioButton->isChecked()){
            this->coll1.append('+');
        }
        if(ui->radioButton_2->isChecked()){
            this->coll1.append('-');
        }
        if(ui->radioButton_3->isChecked()){
            this->coll2.append('*');
        }
        if(ui->radioButton_4->isChecked()){
            this->coll2.append('/');
        }
    });
    connect(ui->radioButton_4, &QRadioButton::toggled, [=](){
        this->coll1 = "";
        this->coll2 = "";
        this->coll = "";
        if(ui->radioButton->isChecked()){
            this->coll1.append('+');
        }
        if(ui->radioButton_2->isChecked()){
            this->coll1.append('-');
        }
        if(ui->radioButton_3->isChecked()){
            this->coll2.append('*');
        }
        if(ui->radioButton_4->isChecked()){
            this->coll2.append('/');
        }
    });
    connect(ui->radioButton_5, &QRadioButton::toggled, [=](){
        if(ui->radioButton_5->isChecked()){
            this->flag = 1;
        }
        else
        {
            this->flag = 0;
        }
    });
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label_14->clear();
        ui->label_15->clear();
        ui->label_16->clear();
        ui->label_17->clear();
        ui->label_18->clear();
        ui->label_19->clear();
        ui->label_20->clear();
        ui->label_21->clear();
        ui->label_22->clear();
        ui->label_23->clear();
        this->maxNum = ui->maxNum->text().toInt();
        this->len = ui->len->text().toInt();
        this->coll = this->coll1 + coll2;
        this->maxNum = ui->maxNum->text().toInt();
        this->len = ui->len->text().toInt();
        this->eq = Calculator::create(10, coll1.toUtf8().data(), coll2.toUtf8().data(), this->maxNum, this->len, this->flag);
        ui->label->setText(QString(this->eq[0]));
        this->res[0] = Calculator::handle(this->eq[0]);
        ui->label_2->setText(QString(this->eq[1]));
        this->res[1] = Calculator::handle(this->eq[1]);
        ui->label_3->setText(QString(this->eq[2]));
        this->res[2] = Calculator::handle(this->eq[2]);
        ui->label_4->setText(QString(this->eq[3]));
        this->res[3] = Calculator::handle(this->eq[3]);
        ui->label_5->setText(QString(this->eq[4]));
        this->res[4] = Calculator::handle(this->eq[4]);
        ui->label_6->setText(QString(this->eq[5]));
        this->res[5] = Calculator::handle(this->eq[5]);
        ui->label_7->setText(QString(this->eq[6]));
        this->res[6] = Calculator::handle(this->eq[6]);
        ui->label_8->setText(QString(this->eq[7]));
        this->res[7] = Calculator::handle(this->eq[7]);
        ui->label_9->setText(QString(this->eq[8]));
        this->res[8] = Calculator::handle(this->eq[8]);
        ui->label_10->setText(QString(this->eq[9]));
        this->res[9] = Calculator::handle(this->eq[9]);
        ui->showPushButton->setEnabled(true);
    });

    connect(ui->showPushButton, &QPushButton::clicked, [=](){
        ui->label_14->setText(QString::number(this->res[0]));
        ui->label_15->setText(QString::number(this->res[1]));
        ui->label_16->setText(QString::number(this->res[2]));
        ui->label_17->setText(QString::number(this->res[3]));
        ui->label_18->setText(QString::number(this->res[4]));
        ui->label_19->setText(QString::number(this->res[5]));
        ui->label_20->setText(QString::number(this->res[6]));
        ui->label_21->setText(QString::number(this->res[7]));
        ui->label_22->setText(QString::number(this->res[8]));
        ui->label_23->setText(QString::number(this->res[9]));
        });

    if(ui->radioButton->isChecked()){
        this->coll1.append('+');
    }
    if(ui->radioButton_2->isChecked()){
        this->coll1.append('-');
    }
    if(ui->radioButton_3->isChecked()){
        this->coll2.append('*');
    }
    if(ui->radioButton_4->isChecked()){
        this->coll2.append('/');
    }

}

Widget::~Widget()
{
    delete ui;
}

