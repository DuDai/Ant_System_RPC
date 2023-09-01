#ifndef ANT_H
#define ANT_H
#include <QVector>
#include <QSet>

class Ant
{
private:
    int id; // ���ϵ�Ψһ��ʶ
    double alpha;   // �������ϵ���Ϣ��������
    double beta;    // �������ϵ�����ѡ������
    int length;    // path���ܳ���
    int rank;   // ��һ�ε��������ϵ�����
    QVector<int> path;   // ��¼�����ߵ�·��
    QSet<int> visited;

public:
    Ant(int _id, double _alpha, double _beta);
    void update(const QVector<QVector<int>>& dist, const QVector<QVector<double>>& pher);  // ���������ߵ���һ���ص�
    int select_next(const QVector<QVector<int>>& dist, const QVector<QVector<double>>& pher);  // ѡ��������һ��Ҫ�ߵĳ���
    void reset();
    int get_length() const;
    int get_rank() const;
    int get_id() const;
    double get_alpha() const;
    double get_beta() const;
    void set_rank(int _rank);
    const QVector<int>& get_path() const;

};

#endif // ANT_H
#pragma once
