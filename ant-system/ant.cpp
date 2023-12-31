#include "ant.h"
#include <iostream>
// #include "RPCClient.hpp"

Ant::Ant(int _id, double _alpha, double _beta)
{
    id = _id;
    alpha = _alpha;
    beta = _beta;
    rank = -1;
    reset();
}

void Ant::reset()
{
    path.clear();
    path.append(0);
    visited.clear();
    visited.insert(0);
    length = 0;
}

int Ant::get_length() const
{
    return length;
}

int Ant::get_rank() const
{
    return rank;
}

int Ant::get_id() const
{
    return id;
}

double Ant::get_alpha() const
{
    return alpha;
}

double Ant::get_beta() const
{
    return beta;
}

void Ant::set_rank(int _rank)
{
    rank = _rank;
}

const QVector<int>& Ant::get_path() const
{
    return path;
}

void Ant::update(const QVector<QVector<int> >& dist, const QVector<QVector<double>>& pher)
{
    int next = select_next(dist, pher);
    length += dist[path.last()][next];
    visited.insert(next);
    path.append(next);
}

int Ant::select_next(const QVector<QVector<int> >& dist, const QVector<QVector<double>>& pher)
{
    int n = dist.size();
    QVector<int> unvis;
    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end()) {
            unvis.append(i);
        }
    }
    if (unvis.empty()) {
        //      ϳ 
        return 0;
    }
    QVector<double> probs;
    double sum;
    for (int c : unvis) {
        double tao = pow(pher[path.last()][c], alpha);
        double yita = pow(1.0 / (dist[path.last()][c] + 1), beta);
        sum += tao * yita;
        probs.push_back(tao * yita);
    }
    double r = (qrand() % RAND_MAX) * 1.0 / RAND_MAX * sum;
    for (int i = 0; i < unvis.size(); ++i) {
        r -= probs[i];
        if (r <= 0) {
            return unvis[i];
        }
    }
    return unvis.last();
}

/* int ant_client(void)
{
    RPCClient clnt("192.168.124.114", 1145);

    int ret0 = clnt.remoteCall("add", 1, 1);
    int ret1 = clnt.remoteCall("subtract", 1, 1);
    int ret2 = clnt.remoteCall("multiply", 4, 2);
    int ret3 = clnt.remoteCall("divide", 4, 2);
    std::cout << "1 + 1 = " << ret0 << std::endl;
    std::cout << "1 - 1 = " << ret1 << std::endl;
    std::cout << "4 * 2 = " << ret2 << std::endl;
    std::cout << "4 / 2 = " << ret3 << std::endl;

    // 异常情况
    try
    {
        clnt.remoteCall("???", 1, 1);
    }
    catch(std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        clnt.remoteCall("divide", 1, 0);
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
} */
