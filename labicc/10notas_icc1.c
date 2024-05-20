#include <stdio.h>

void leia(float t[110][30], int n, int m);
void calcula(float t[110][30], int n, int m, float m_aluno[110], float m_exe[30]);
void escreva(int n, int m, float m_aluno[110], float m_exe[30]);
void sort(int m, float t[30]);

int main(void) {
    int n, m;
    float t[110][30], m_aluno[110], m_exe[30];
    scanf("%d%d", &n, &m);
    leia(t, n, m);
    calcula(t, n, m, m_aluno, m_exe);
    sort(m, m_exe);
    escreva(n, m, m_aluno, m_exe);
}

void leia(float t[110][30], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%f", &t[i][j]);
        }
    }
}

void calcula(float t[110][30], int n, int m, float m_aluno[110], float m_exe[30]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            m_aluno[i] += t[i][j];
            m_exe[j] += t[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        m_aluno[i] /= m;
    }
    for (int i = 0; i < m; i++) {
        m_exe[i] /= n;
    }
}

void escreva(int n, int m, float m_aluno[110], float m_exe[30]) {
    for (int i = 0; i < n; i++) {
        printf("Media do aluno %d = %.2f : ", i+1, m_aluno[i]);
        if (m_aluno[i] >= 5.0) {
            printf("Aprovado\n");
        } else {
            printf("Reprovado\n");
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++) {
        printf("%.2f ", m_exe[i]);
    }
    printf("\n");
}

void sort(int m, float t[30]) {
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (t[i] < t[j]) {
                float tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}