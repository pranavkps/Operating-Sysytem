#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node{
  int pno,at,bt;
  struct node *next;
}*head;

struct node *createnode(int pno,int at,int bt){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->pno = pno;
  newnode->at = at;
  newnode->bt = bt;
  newnode->next = NULL;
  return newnode;
}
void readyq(int pno,int at,int bt){
  struct node *newnode = createnode(pno,at,bt);
  struct node *temp = head;
  if(head==NULL || temp->at > at){
    newnode->next = head;
    head = newnode;
  }
  else{
    while(temp->next != NULL && temp->next->at <= at) temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
  }
}
void rr(int at[],int bt[],int ct[],int k,int n){
  int i;
  for(i=0;i<n;i++) readyq(i,at[i],bt[i]);

  struct node *temp = head;
  int t = 0;
  while(temp!=NULL){
    if(temp->at > t) t = temp->at;

    if(temp->bt > k){
      t += k;
      readyq(temp->pno,t,temp->bt-k);
    }
    else{
      t += temp->bt;
      ct[temp->pno] = t;
    }
    temp = temp->next;
  }
}
void main(){
  int i,n; printf("ENTER NO OF PROCESS :"); scanf("%d",&n);
  int at[n],bt[n],ct[n],temp_b[n],tat[n],wt[n],k;
  for(i=0;i<n;i++){
    printf("ENTER AT & BT :");
    scanf("%d%d",&at[i],&bt[i]);
    temp_b[i]=bt[i];
  }
  printf("ENTER TIME-QUANTUM :"); scanf("%d",&k);

  rr(at,bt,ct,k,n);

  int t_tat = 0, t_wt = 0;
  for(i=0;i<n;i++){
    tat[i] = ct[i] - at[i];
    t_tat += tat[i];
    wt[i] = tat[i] - bt[i];
    t_wt += wt[i];
  }
  printf("\nat\tbt\tct\ttat\twt\n"); 
  for(i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\t%d\n",at[i],temp_b[i],ct[i],tat[i],wt[i]);
  
  printf("\nAVG WT :%d\nAVG TAT :%d",(t_tat/n),(t_wt/n));
}