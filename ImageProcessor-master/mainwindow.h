#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

class Image
{
public:
    std::string tipo;
    int width;
    int height;
    int maxColor;
    int *matrix;

    Image(char *arquivo);
    ~Image();
    int imageToFile(char* path);
    int negativo(char *path);
    int brilho(char *path);
    int sepia(char *path);
    int setMatrix();
};

char* onlyPath(char* img_path);
#endif // MAINWINDOW_H
