#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <QWidget>
#include <QMainWindow>
#include <QTextBrowser>
#include <QPushButton>
#include <QTextStream>
#include <QTimer>
#include <QVector>
#include <QVBoxLayout>
#include <QInputDialog>
#include <QHBoxLayout>
#include <QFile>
#include "colony.h"
#include "viewer.h"
#include "manager.h"

class Simulator : public QWidget
{
    Q_OBJECT
private:
    Colony* colony;
    int count;
    QTimer* timer;
    QVector<QPoint> map;
    int best_record;
    QVector<int> best_record_path;
    Viewer* viewer;
    Manager* manager;
    QTextBrowser* info;
    QPushButton* set_map;
    QPushButton* simulate;
    QPushButton* best_btn;
    QSpinBox* speed_box;

public:
    explicit Simulator(QWidget* parent = 0);
    ~Simulator();

private:
    void update_info();  // ����info���
    void print_summary();    // ����info��壬�������ܽ�
    void load_map(); // ���ļ�map.txt�м��ص�ͼ
    void save_map();    // �����ͼ�ļ�

signals:
    void record_changed(int new_record);

private slots:
    void on_show_best_clicked();    // չʾ���·��
    void simulate_end();  // ֹͣ��ʱ��������record
    void update();   // �������ݲ�ˢ�����
    void on_simulate_clicked(); // ����ʼ��ť�����£�����ģ��
    void on_set_map_clicked();    // �����õ�ͼ��ť�����£������ͼ
};

#endif // SIMULATOR_H
#pragma once
