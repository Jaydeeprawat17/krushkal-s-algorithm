#include<iostream.h>
#include<conio.h>
#include<string.h>
#define max 17
#define size 26

struct graph{
 char v1,v2;
 int weight;
};
struct MST{
char v1,v2;
int weight;
};

class krushkal_algo{
struct graph graph[max];
struct MST tree[max];
int edge,vertix,tree_length;
char singlton_set[size];
public:

krushkal_algo(){
 vertix=edge=tree_length=0;
}

void insert_graph(){
cout<<"Enter Vertices and their weights"<<endl;
cout<<"Enter No of Edges of Graph G: ";
cin>>edge;


 for(int s=0;s<edge;s++){
   cout<<"Insert "<<s+1<<" v1 and v2 And weight"<<endl;
   cin>>graph[s].v1>>graph[s].v2>>graph[s].weight;
   clrscr();
   }
 }

   void sort(){
     for(int s=1;s<edge;s++){
	for(int j=0;j<edge-s;j++){
	   if(graph[j].weight>graph[j+1].weight){
	     char v1,v2;
	     int weight;
	     v1=graph[j].v1;
	     v2=graph[j].v2;
	     weight=graph[j].weight;

	     graph[j].v1=graph[j+1].v1;
	     graph[j].v2=graph[j+1].v2;
	     graph[j].weight=graph[j+1].weight;

	     graph[j+1].v1=v1;
	     graph[j+1].v2=v2;
	     graph[j+1].weight=weight;
	   }
	}
     }
   }

   void show(){
    for(int s=0;s<edge;s++)
      cout<<graph[s].v1<<" "<<graph[s].v2<<" "<<graph[s].weight<<endl;

   }
   // its ok to check is vertix is exits in or not but have to change

   int is_present(char c){
      for(int s=0;s<vertix;s++){
	 if(singlton_set[s++]=='{'){
	   if(singlton_set[s++]==c) return 1;
	 }
      }

     return 0;
   }
 // {a}{b}{c}{d}{e}{f}
 void make_singlton_set(){
    for(int s=0;s<edge;s++){
	if(!is_present(graph[s].v1)){
	    singlton_set[vertix++]='{';
	    singlton_set[vertix++]=graph[s].v1;
	    singlton_set[vertix++]='}';
	    singlton_set[vertix]='\0';
	}
	if(!is_present(graph[s].v2)){
	    singlton_set[vertix++]='{';
	    singlton_set[vertix++]=graph[s].v2;
	    singlton_set[vertix++]='}';
	    singlton_set[vertix]='\0';
	}
    }
    cout<<singlton_set;
 }

 char* find_set(char v){
   char v1[size];
     v1[0]='\0';
     int len=0;
    // {A B } find B = {B}
   for(int s=0;s<vertix;s++){
      if(singlton_set[s]==v && singlton_set[s-1]=='{'){
	 v1[len++]='{';
	 v1[len++]=singlton_set[s++];
	 while(singlton_set[s]!='}') {
	    v1[len++]=singlton_set[s++];
	 }

	 v1[len++]='}';
	 v1[len]='\0';
	 return v1;
      }else if(singlton_set[s]==v && singlton_set[s-1]!='{'){

	 for(int k=s;k>=0;k--){
	     if(singlton_set[k]=='{')
	       break;
	 }
      //	v1[len++]='{';
	s=k;
	 while(singlton_set[s]!='}'){
	      v1[len++]=singlton_set[s++];
	 }
	 v1[len++]='}';
	 v1[len]='\0';
	 return v1;
      }
   }

 }
 void union_set(char u[size],char v[size]){
  char newset[size];
  int length=0,s=0;
    while(s<strlen(u)-1){
       newset[length++]=u[s++];
    }
    s=1;
    while(s<strlen(v)){
     newset[length]=v[s++];
     length++;
    }
    newset[length]='\0';
    int count_vertix=0,start;
    s=1;

    for(s=0;s<vertix;s++){
    count_vertix=0;
	if(singlton_set[s+1]==u[1]){
	    start=s;
	   while(singlton_set[s++]!='}')
	     count_vertix++;


	    count_vertix++; //due to also add '}'

	  s=start;
	 for(int j=start;j<vertix;j++)
	    singlton_set[j]=singlton_set[j+count_vertix];

	    singlton_set[j]='\0';
	    vertix=j;
	break;
       }
    }
    for(s=0;s<vertix;s++){
    count_vertix=0;
	if(singlton_set[s+1]==v[1]){
	       start=s;

		 while(singlton_set[s++]!='}')
		    count_vertix++;

		  count_vertix++;// due to also add '}'
		    s=start;

		 for(int j=start;j<vertix;j++)
		     singlton_set[j]=singlton_set[j+count_vertix];
	 singlton_set[j]='\0';
	 vertix=j;

       break;
      }
    }
     vertix=strlen(singlton_set);

    for(s=0;s<strlen(newset);s++){
      singlton_set[vertix++]=newset[s];
    }
    singlton_set[vertix]='\0';
}

 void krushkal(){
   char u[size],v[size];

    for(int s=0;s<edge;s++){
       strcpy(u,find_set(graph[s].v1));
       strcpy(v,find_set(graph[s].v2));

       if(stricmp(u,v)!=0){
	 tree[tree_length].v1=graph[s].v1;
	 tree[tree_length].v2=graph[s].v2;
	 tree[tree_length++].weight=graph[s].weight;
	    union_set(u,v);
       }
    }

 }

 void show_mst(){
   cout<<endl<<"selected vertix: "<<singlton_set<<endl;

  for(int s=0;s<tree_length;s++){
      cout<<tree[s].v1<<" "<<tree[s].v2<<":"<<tree[s].weight<<endl;
   }
 }

};
void main(){
clrscr();
krushkal_algo p1;

p1.insert_graph();
p1.sort();
p1.show();
getch();
p1.make_singlton_set();
p1.krushkal();
p1.show_mst();
getch();
}