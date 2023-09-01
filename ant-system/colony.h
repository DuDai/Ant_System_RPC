#ifndef COLONY_H
#define COLONY_H
#include "ant.h"
#include <QPoint>

class Colony
{
private:
    int n;  // ������Ŀ
    double rou; // ��Ϣ˥ɢ����
    double increment;   // ���Ϸ�����Ϣ�ص���
    int target; // ϣ��ͻ�Ƶ�Ŀ�꣬���������ͻ�ƣ����輫��Ľ���(targetΪ-1ʱֱ�Ӻ���)
    int push;   // ����������
    int best;   // ��colony������Ϊֹ���ֵ�����·������
    QVector<int> best_path;  // ��colony������Ϊֹ���ֵ�����·��
    QVector<Ant*> ants; // �洢���е�����ָ��
    QVector<QVector<int>> dist;   // �洢�����ص�֮��ľ���
    QVector<QVector<double>> pher; // �洢�����ص�֮�����Ϣ��Ũ��
public:
    Colony(QVector<QPoint>& map, int ants_num, double rou, double increment, int record, int push, double _alpha_value, double _beta_value,
        double _alpha_bias, double _beta_bias);  // ���캯������Ҫ�����������ϲ����ص�ͼ
    ~Colony();
    void update(); // һ����������������������������ȫ��·�̲�������Ϣ��״̬
    void update_pher();  // ������Ϣ��Ũ��
    int get_best() const;
    const QVector<int> get_best_path() const;
    const QVector<Ant*>& get_ants() const;
    const QVector<QVector<double>>& get_pher() const;

};

#endif // COLONY_H
#pragma once
