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
#include <bits/stdc++.h>

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
    int i;
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
    int i=0;
    // Generate and write the pixel data
    while(i<height*width*3){
        if(i%510!=509 && i!=1919){
            outputFile << matrix[i] << " ";
        }
        else{
            outputFile << matrix[i] << " ";
            outputFile << endl;
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
    int i=0,j;
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

int Image::brilho(char *path){
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
    int i=0,j,val;
    // Generate and write the pixel data
    while(i<height*width*3){
        if(j!=509){
            val = matrix[i]+matrix[i]/5;
            if(val < 255){
                outputFile << val << " ";
            }
            else{
                outputFile << 255 << " ";
            }
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

int Image::sepia(char *path){
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
    int i=0,j,val;
    // Generate and write the pixel data
    while(i<height*width*3){
        if(j!=509){
            /*tr = 0.393R + 0.769G + 0.189B
            tg = 0.349R + 0.686G + 0.168B
            tb = 0.272R + 0.534G + 0.131B*/
            if(i%3==0){
                val = 0.393*matrix[i] + 0.769*matrix[i+1] + 0.189*matrix[i+2];
                if(val < 255 ){
                    outputFile << val << " ";
                }
                else{
                    outputFile << 255 << " ";
                }
            }
            else if(i%3==1){
                val = 0.349*matrix[i-1] + 0.686*matrix[i] + 0.168*matrix[i+1];
                if(val < 255 ){
                    outputFile << val << " ";
                }
                else{
                    outputFile << 255 << " ";
                }
            }
            else{
                val = 0.272*matrix[i-2] + 0.534*matrix[i-1] + 0.131*matrix[i];
                if(val < 255 ){
                    outputFile << val << " ";
                }
                else{
                    outputFile << 255 << " ";
                }
            }
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
    time_t start, end;
    start = clock();
    string spath,teste;
    ifstream asd;
    char* tmp;
    asd.open("path.txt");
    getline(asd,teste,',');
    cout << teste << endl;
    tmp = strToChar(teste);
    Image imagem(tmp);
    imagem.brilho(onlyPath(tmp));
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
    end = clock();
    double tempo = double(end - start) / double(CLOCKS_PER_SEC);
    string stempo = to_string(tempo);
    QString qtempo = QString::fromStdString(stempo);
    ui->label_3->setText(qtempo);
}


void MainWindow::on_pushButton_3_clicked()
{
    time_t start, end;
    start = clock();
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
    end = clock();
    double tempo = double(end - start) / double(CLOCKS_PER_SEC);
    string stempo = to_string(tempo);
    QString qtempo = QString::fromStdString(stempo);
    ui->label_3->setText(qtempo);
}


void MainWindow::on_pushButton_4_clicked()
{
    time_t start, end;
    start = clock();
    string spath,teste;
    ifstream asd;
    char* tmp;
    asd.open("path.txt");
    getline(asd,teste,',');
    cout << teste << endl;
    tmp = strToChar(teste);
    Image imagem(tmp);
    imagem.sepia(onlyPath(tmp));
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
    end = clock();
    double tempo = double(end - start) / double(CLOCKS_PER_SEC);
    string stempo = to_string(tempo);
    QString qtempo = QString::fromStdString(stempo);
    ui->label_3->setText(qtempo);
}

