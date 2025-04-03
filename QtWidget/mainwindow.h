#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_PB_add10_clicked(); // Слот для кнопки увеличения прогресса
    void on_rB_BlokPrgBr_toggled(bool checked); // Слот для радио-кнопки блокировки прогресс-бара
    void on_rB_SlcLst_toggled(bool checked); // Слот для радио-кнопки выбора из списка
    void on_cB_Options_currentIndexChanged(int index); // Слот для изменения опции в списке

private:
    Ui::MainWindow *ui;
    void updateProgressBar(int increment);
};
#endif // MAINWINDOW_H
