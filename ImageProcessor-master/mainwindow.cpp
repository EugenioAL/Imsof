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

char* strToChar(string word){
    int tam = word.size();
    char *vet = new char[tam];
    for(int i=0;i<tam;i++){
        vet[i] = word[i];
    }
    return vet;
}

char* onlyPath(char* img_path){
    char* dir;

    int cont = 0,barInd = 0;

    while(img_path[cont] != '\0'){
        if(img_path[cont] == '\\' || img_path[cont] == '/'){
            barInd = cont + 1;
        }
        cont++;
    }

    dir = img_path;

    for(barInd;barInd < cont;barInd++ ){
        dir[barInd] = '\0';
    }

    return dir;
}

int copyImage(char *nome){
    ofstream entrada;
    ifstream saida;
    string line,diretorio = (string)onlyPath(nome) + "copia.ppm";
    int cont = 0;
    char* cdir = strToChar(diretorio);
    cout << diretorio << endl;
    saida.open(nome);
    entrada.open(cdir);
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

//read image using QFileDialog
void MainWindow::on_pushButton_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("Images (*.ppm)"));
    string img_path = file_name.toStdString();
    char* arquivo = onlyPath(strToChar(img_path));
    string spath = (string)arquivo,teste;
    ofstream doc;
    doc.open("path.txt");
    doc << img_path;
    doc.close();
    spath = spath + "copia.ppm";

    if (!file_name.isEmpty()){

        //open prompt and display image
        QImage img(file_name);
        QPixmap pix = QPixmap::fromImage(img);
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}







void MainWindow::on_pushButton_2_clicked()
{
    string spath,teste;
    ifstream asd;
    asd.open("path.txt");
    getline(asd,teste);
    cout <<"teste " << teste << endl;
    asd.close();
    QString qpath = QString::fromStdString(teste);
    if (!qpath.isEmpty()){

        //open prompt and display image
        QImage img(qpath);
        QPixmap pix = QPixmap::fromImage(img);
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

