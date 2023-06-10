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

Image::Image(char* arquivo){
    ifstream entrada;
    int i,j,val,celula=0;
    entrada.open(arquivo);
    string line,line2, erro;
    getline(entrada,line);
    this->tipo = line;
    getline(entrada,line,' ');
    this->width = stoi(line);
    getline(entrada,line);
    this->height = stoi(line);
    getline(entrada,line);
    this->maxColor = stoi(line);
    matrix = new int[width*height*3];
    i=0;
    while(getline(entrada,line)){
        stringstream ss(line);
        while(getline(ss,line2,' ')){
            try {
                matrix[i] = stoi(line2);
                i++;
            } catch (...) {
            }
        }
    }
    entrada.close();
}

Image::~Image(){

}

int Image::imageToFile(char *path){
    int width = this->width;
    int height = this->height;
    int maxColorValue = this->maxColor;
    string caminho = string(path)+"copia.ppm";
    ofstream outputFile(strToChar(caminho));
    if (!outputFile) {
        std::cerr << "Failed to create the output file." << std::endl;
        return 0;
    }

    // Write the PPM header
    outputFile << "P3" << std::endl;
    outputFile << width << " " << height << std::endl;
    outputFile << maxColorValue << std::endl;
    int i,j;
    // Generate and write the pixel data
    while(i<height*width*3){
        if(j!=509){
            outputFile << matrix[i] << " ";
            j++;
        }
        else{
            outputFile << matrix[i] << " ";
            outputFile << endl;
            j =0;
        }
        i++;
    }
    outputFile.close();
    std::cout << "Image generated successfully." << std::endl;
    return 1;
}

int Image::negativo(char *path){
    int width = this->width;
    int height = this->height;
    int maxColorValue = this->maxColor;
    string caminho = string(path)+"copia.ppm";
    ofstream outputFile(strToChar(caminho));
    if (!outputFile) {
        std::cerr << "Failed to create the output file." << std::endl;
        return 0;
    }

    // Write the PPM header
    outputFile << "P3" << std::endl;
    outputFile << width << " " << height << std::endl;
    outputFile << maxColorValue << std::endl;
    int i,j;
    // Generate and write the pixel data
    while(i<height*width*3){
        if(j!=509){
            outputFile << 255 - matrix[i] << " ";
            j++;
        }
        else{
            outputFile << matrix[i] << " ";
            outputFile << endl;
            j =0;
        }
        i++;
    }
    outputFile.close();
    std::cout << "Image generated successfully." << std::endl;
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
        ui->label_pic_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    string spath,teste;
    ifstream asd;
    char* tmp;
    asd.open("path.txt");
    getline(asd,teste,',');
    cout << teste << endl;
    tmp = strToChar(teste);
    Image imagem(tmp);
    imagem.imageToFile(onlyPath(tmp));
    teste = string(onlyPath(tmp))+"copia.ppm";
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


void MainWindow::on_pushButton_3_clicked()
{
    string spath,teste;
    ifstream asd;
    char* tmp;
    asd.open("path.txt");
    getline(asd,teste,',');
    cout << teste << endl;
    tmp = strToChar(teste);
    Image imagem(tmp);
    imagem.negativo(onlyPath(tmp));
    teste = string(onlyPath(tmp))+"copia.ppm";
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

