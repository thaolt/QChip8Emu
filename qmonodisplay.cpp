#include "qmonodisplay.h"
#include <QPainter>
#include <QBrush>

QMonoDisplay::QMonoDisplay(QWidget *parent) : QWidget(parent)
{
    this->m_width = 64;
    this->m_height= 32;
    this->m_displayMatrix = new QVector<qint8>(this->m_width * this->m_height, 0);
}

void QMonoDisplay::pixelSet(int x, int y)
{
    this->m_displayMatrix->replace(y*this->m_width + x, 1);
    this->update();
}

void QMonoDisplay::pixelClear(int x, int y)
{
    this->m_displayMatrix->replace(y*this->m_width + x, 0);
    this->update();
}

void QMonoDisplay::pixelToggle(int x, int y)
{
    int val = this->m_displayMatrix->at(y*this->m_width + x);
    if (val > 0) {
        val = 0;
    } else {
        val = 1;
    }
    this->m_displayMatrix->replace(y*this->m_width + x, val);
    this->update();
}

void QMonoDisplay::screenClear()
{
    this->m_displayMatrix->fill(0);
    this->update();
}

void QMonoDisplay::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.fillRect(this->rect(), QBrush(Qt::GlobalColor::black));

    int blockw = this->rect().width() / this->m_width;
    int blockh = this->rect().height() / this->m_height;

    for (int i = 0; i < this->m_height; ++i) {
        for (int j = 0; j < this->m_width; ++j) {
            if (this->m_displayMatrix->at(i*this->m_width + j) > 0) {
                int realx = j * blockw;
                int realy = i * blockh;
                painter.fillRect(realx, realy, blockw, blockh, QBrush(Qt::GlobalColor::white));
            }
        }
    }

    QWidget::paintEvent(e);
}
