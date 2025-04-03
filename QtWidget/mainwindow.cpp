#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include <QLabel>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rB_SlcLst->setUpdatesEnabled(true);
    ui->cB_Options->setUpdatesEnabled(true);
    ui->rB_BlokPrgBr->setUpdatesEnabled(true);
    ui->pB_10->setUpdatesEnabled(true);
    ui->menubar->setUpdatesEnabled(true);
    ui->PB_add10->setUpdatesEnabled(true);
    ui->pB_10->setMinimum(0);
    ui->pB_10->setMaximum(100);
    ui->pB_10->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//сигналы
void MainWindow::on_PB_add10_clicked()
{
    int increment = 10; // По умолчанию увеличиваем на 10

    // Изменяем величину увеличения в зависимости от выбранного элемента в cB_Options
    switch (ui->cB_Options->currentIndex()) {
    case 0: increment = 10; break;   // Увеличить на 1
    case 1: increment = 20; break;   // Увеличить на 2
    case 2: increment = 50; break;   // Увеличить на 5
    case 3: increment = 25; break;  // Увеличить на 25%
    case 4: increment = 1; break;   // Увеличить на 1%
    }
    if (ui->PB_add10->isChecked()){
        updateProgressBar(increment);}
}

void MainWindow::updateProgressBar(int increment)
{
    int currentValue = ui->pB_10->value();
    currentValue += increment;

    // Если превышает максимум, сбрасываем
    if (currentValue > 100) {
        currentValue = 0;
    }

    ui->pB_10->setValue(currentValue);
}

void MainWindow::on_rB_BlokPrgBr_toggled(bool checked)
{
    if (checked) {
        ui->pB_10->hide(); // Скрыть другой объект
    } else {
        ui->pB_10->show(); // Показать другой объект
    }
    ui->pB_10->setEnabled(!checked); // Блокируем или разблокируем прогресс-бар
}

void MainWindow::on_rB_SlcLst_toggled(bool checked)
{
    if (!checked) {
        ui->cB_Options->show(); // Скрыть другой объект
    } else {
        ui->cB_Options->hide(); // Показать другой объект
    }
    ui->cB_Options->setEnabled(checked); // Блокируем или разблокируем выпадающий список
}

void MainWindow::on_cB_Options_currentIndexChanged(int index)
{
    // Обновляем текст кнопки в зависимости от выбранной опции
    QString buttonText;
    switch (index) {
    case 0: buttonText = "Увеличить на 1"; break;
    case 1: buttonText = "Увеличить на 2"; break;
    case 2: buttonText = "Увеличить на 5"; break;
    case 3: buttonText = "Увеличить на 25%"; break;
    case 4: buttonText = "Увеличить на 1%"; break;
    }
    ui->PB_add10->setText(buttonText);
}



class ProgressBarWidget : public QWidget {
    Q_OBJECT
public:
ProgressBarWidget(QWidget *parent = nullptr) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Создание элементов интерфейса
    cB_Options = new QComboBox(this);
    cB_Options->addItems({"Увеличить на 1", "Увеличить на 2", "Увеличить на 5", "Увеличить на 25%", "Увеличить на 1%"});
    layout->addWidget(cB_Options);

    rB_BlokPrgBr = new QRadioButton("Блокировать прогресс бар", this);
    layout->addWidget(rB_BlokPrgBr);

    rB_SlcLst = new QRadioButton("Разрешить выбор опций", this);
    layout->addWidget(rB_SlcLst);

    pB_10 = new QPushButton("Увеличить на 10%", this);
    layout->addWidget(pB_10);

    pB_ProgressBar = new QProgressBar(this);
    pB_ProgressBar->setMinimum(0);
    pB_ProgressBar->setMaximum(10);
    layout->addWidget(pB_ProgressBar);

    // Подключение сигналов к слотам
    connect(pB_10, &QPushButton::clicked, this, &ProgressBarWidget::increaseProgress);
    connect(rB_BlokPrgBr, &QRadioButton::toggled, this, &ProgressBarWidget::toggleProgressBar);
    connect(rB_SlcLst, &QRadioButton::toggled, this, &ProgressBarWidget::toggleComboBox);
    connect(cB_Options, &QComboBox::currentIndexChanged, this, &ProgressBarWidget::updateButtonText);

    // Изначально отключаем радио-кнопки
    rB_BlokPrgBr->setChecked(false);
    rB_SlcLst->setChecked(true);
}

private slots:
void increaseProgress() {
    if (rB_BlokPrgBr->isChecked()) return; // Если заблокировано, ничего не делать

    int increment = 10; // По умолчанию 10%
    switch (cB_Options->currentIndex()) {
    case 0: increment = 10; break;   // Увеличить на 1
    case 1: increment = 20; break;   // Увеличить на 2
    case 2: increment = 50; break;   // Увеличить на 5
    case 3: increment = 25; break;   // Увеличить на 25%
    case 4: increment = 1; break;   // Увеличить на 1%
    }

    int value = pB_ProgressBar->value();
    value += increment;


    if (value > pB_ProgressBar->maximum()) {
        value = 0; // Сброс до 0, если превышает максимум
    }


    pB_ProgressBar->setValue(value);
    updateButtonText(); // Обновление текста кнопки


}

void toggleProgressBar(bool checked) {
    pB_ProgressBar->setEnabled(!checked); // Блокируем или разблокируем прогресс бар
}

void toggleComboBox(bool checked) {
    cB_Options->setEnabled(checked); // Блокируем или разблокируем выпадающий список
}

void updateButtonText() {
    int increment = 10; // По умолчанию 10%
    switch (cB_Options->currentIndex()) {
    case 0: increment = 1; break;   // Увеличить на 1
    case 1: increment = 2; break;   // Увеличить на 2
    case 2: increment = 5; break;   // Увеличить на 5
    case 3: increment = 3; break;   // Увеличить на 25%
    case 4: increment = 1; break;   // Увеличить на 1%
    }

    pB_10->setText(QString("Увеличить на %1%").arg(increment * 10 / 10)); // Обновление текста кнопки
}

private:
QComboBox *cB_Options;
QRadioButton *rB_BlokPrgBr;
QRadioButton *rB_SlcLst;
QPushButton *pB_10;
QProgressBar *pB_ProgressBar;
};





#include "mainwindow.moc"

