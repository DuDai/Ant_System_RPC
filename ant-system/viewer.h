#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QVector>
#include <QPainter>
#include <QResizeEvent>
#include <QColor>
#include "colony.h"

class Viewer : public QWidget
{
    Q_OBJECT
private:
    QPixmap canvas;
    QVector<QPoint> map;  // ��ͼ�ı���
public:
    explicit Viewer(QWidget* parent = nullptr);
    void update(const Colony* colony, bool best = 0);  // Ĭ����ʾcolony�����·��
    void initialize(const QVector<QPoint>& _map); // ��ʼ����ͼ����
    void paintEvent(QPaintEvent* event);
    void show_path(const QVector<int>& path);
};

#endif // VIEWER_H
#pragma once
