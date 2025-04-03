#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �ݹ�ⷨ
void hanoi_recursive(int n, char from, char to, char aux, int *step) {
    if (n == 1) {
        printf("���� %d: �ƶ�Բ�� 1 �� %c �� %c\n", ++(*step), from, to);
        return;
    }
    hanoi_recursive(n-1, from, aux, to, step);
    printf("���� %d: �ƶ�Բ�� %d �� %c �� %c\n", ++(*step), n, from, to);
    hanoi_recursive(n-1, aux, to, from, step);
}


void hanoi_iterative(int n) {
    char poles[3] = {'A', 'B', 'C'};
    int total = pow(2,n)-1;
    int* disk_pos = (int*)malloc(n*sizeof(int));
    
    for(int i=0; i<n; i++) disk_pos[i]=0;
    
    int direction = (n%2)?1:-1; // ��ż�������
    
    for(int step=1; step<=total; step++){
        // Ѱ����С���ƶ�Բ��
        for(int d=0; d<n; d++){
            int curr = disk_pos[d];
            int next = (curr + direction +3)%3;
            bool movable = true;
            
            for(int k=0; k<d; k++)
                if(disk_pos[k]==curr || disk_pos[k]==next)
                    movable = false;
            
            if(movable){
                printf("���� %d: �ƶ�Բ�� %d �� %c �� %c\n",
                      step, d+1, poles[curr], poles[next]);
                disk_pos[d] = next;
                break;
            }
        }
    }
    free(disk_pos);
}

int main() {
    int n, step = 0;
    printf("����Բ������: ");
    scanf("%d", &n);
    
    printf("\n�ݹ鷽��:\n");
    hanoi_recursive(n, 'A', 'C', 'B', &step);
    
    printf("\n�ܲ���: %d (Theory: %.0f)\n", step, pow(2, n)-1);
    
    printf("\n��������:\n");
    hanoi_iterative(n);
    
    return 0;
}
