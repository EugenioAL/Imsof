#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QQueue>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int copyImage(char *nome){
    ofstream entrada;
    ifstream saida;
    string line,diretorio = nome;
    int cont = 0;
    saida.open(nome);
    entrada.open(diretorio + "(copia)");
    if(saida.is_open()){
        while(getline(saida,line))
        {
            entrada << line << endl;
            cont++;
        }
    }
    else{
        return 0;
    }
    cout << endl << cont << endl;
    entrada.close();
    saida.close();

    return 1;
}

char* strToChar(string word){
    int tam = word.size();
    char *vet = new char[tam];
    for(int i=0;i<tam;i++){
        vet[i] = word[i];
    }
    return vet;
}

//read image using QFileDialog
void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.ppm)"));
    string img_path = file_name.toStdString();
    char* arquivo = strToChar(img_path);
    cout << copyImage(arquivo) << endl;
    if (!file_name.isEmpty()){

        //open prompt and display image
        QImage img(file_name),copy(file_name.append("(copia)"));
        QPixmap pix = QPixmap::fromImage(img);
        QPixmap pixc = QPixmap::fromImage(copy);
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        ui->label_pic_2->setPixmap(pixc.scaled(w,h,Qt::KeepAspectRatio));
    }
}






