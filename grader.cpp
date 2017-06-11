#include "grader.h"
#include "ui_grader.h"

grader::grader(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grader)
{
    ui->setupUi(this);

    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_2,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_3,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_4,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_5,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_6,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_7,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_8,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_9,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_10,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
    QObject::connect(ui->spinBox_11,SIGNAL(valueChanged(int)),
                     this,SLOT(update_overall(int)));
}

grader::~grader()
{
    delete ui;
}

double grader::compute_overall(int unused){
    double overall= 0;
    double score = static_cast<double>(unused);
    scores.push_back(score);
    if(ui -> radioButton -> isChecked()){
        for(int i = 0; i < scores.size(); i++){
            overall += score * 0.1;
        }
    }
    if(ui -> radioButton -> isChecked()){
        for(int i = 0; i < scores.size(); i++){
            overall += score * 0.2;
        }
    }
    return overall;
}

void grader::update_overall(int unused){
    // double score = 31.4;
    double score = compute_overall(unused);

    ui->label_14->setText(QString::number(score));

    return;
}
