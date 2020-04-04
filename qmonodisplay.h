#ifndef QMONODISPLAY_H
#define QMONODISPLAY_H

#include <QObject>
#include <QWidget>
#include <QVector2D>

class QMonoDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit QMonoDisplay(QWidget *parent = nullptr);

public slots:
    void pixelSet(int x, int y);
    void pixelClear(int x, int y);
    void pixelToggle(int x, int y);
    void screenClear();

signals:

protected:
    void paintEvent(QPaintEvent *e);

private:
    QVector<qint8> *m_displayMatrix;
    qint8 m_width;
    qint8 m_height;

};

#endif // QMONODISPLAY_H
