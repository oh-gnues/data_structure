#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq) {        // �� �� ��� front�� rear�� ���� ��ġ ����Ŵ
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue * pq) {          // ť�� �� ����ٸ�,
    if (pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

int NextPosIdx(int pos) {           // ť�� ���� ��ġ�� �ش��ϴ� �ε��� �� ��ȯ
    if (pos == QUE_LEN -1)          // �迭�� ������ ����� �ε��� ���̶��
        return 0;
    else
        return pos + 1;
}

void Enqueue(Queue * pq, Data data) {
    if (NextPosIdx(pq->rear) == pq->front) {    // ť�� �� á�ٸ�,
        printf("Queue Memory Error !");
        exit(-1);
    }

    pq->rear = NextPosIdx(pq->rear);    // rear�� �� ĭ �̵�
    pq->queArr[pq->rear] = data;        // rear�� ����Ű�� ���� ������ ����
}

Data Dequeue(Queue * pq) {
    if (QIsEmpty(pq)) {
        printf("Queue Memory Error !");
        exit(-1);
    }

    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

Data QPeek(Queue * pq) {
    if (QIsEmpty(pq)) {
        printf("Queue Memory Error !");
        exit(-1);
    }

    return pq->queArr[NextPosIdx(pq->front)];
}