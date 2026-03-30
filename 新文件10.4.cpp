#include<bits/stdc++.h>
using namespace std;
int main()
{
	int p,q,x,y,tx,ty,n1=0,n2=0,num=1,step,det=0,tes;
	int turn[2]={119,98},dir[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};//119白98黑
	char b='b',w='w',a;//用於最後數棋子 
	cout<<"請輸入棋盤長寬"<<endl;
	cin>>p>>q;
	char z[p+2][q+2];
    for(int i=1;i<=p;i++)
        for(int j=1;j<=q;j++)
            z[i][j]='.';//填滿空格
    for(int i=0;i<=p+1;i++)
    {
        z[i][0]=(char)64+i;
        z[0][i]=i+'0';
    } 
    z[0][0]='/';
    z[p/2][q/2]=w;z[p/2+1][q/2+1]=w;z[p/2][q/2+1]=b;z[p/2+1][q/2]=b; //設定棋盤初始長相
    cout<<"-----------------------"<<endl;
    cout<<"@處為可落子點"<<endl;
    cout<<"落子位置輸入列加行,ex:A5"<<endl;
    cout<<"輸入L時結束並結算"<<endl;
    while(num>0&&det!=2)
    {
        num=0;tes=0;det=0;
        for(int n=1;n<=p;n++)
        	for(int m=1;m<=q;m++)
            	if(z[n][m]=='.')//若(n,m)依然為空 
            	{
            		for(int i=0;i<=7;i++)//搜尋八個方位 
           			{
            			step=1;
                		tx=n+dir[i][0]*step;ty=m+dir[i][1]*step;//尋找有效下棋處，有效則填上@ 
                		while(z[tx][ty]==(char)turn[1])
                		{
                    		step+=1;
                   			tx=n+dir[i][0]*step;ty=m+dir[i][1]*step;
                		}
                		if(z[tx][ty]==(char)turn[0]&&step>1)
                		{
                			z[n][m]='@';
                			det=0;
                			tes+=1;//有幾格能放 
                			break;
                		}
					}
				}
		if(tes>0)
		{
			cout<<"-----------------------"<<endl;
        	for(int i=0;i<=p;i++)
    		{
      			for(int j=0;j<=q;j++)
            		cout<<z[i][j]<<" ";
        		cout<<endl;//輸出棋盤
    		}
    		cout<<"-----------------------"<<endl;
        	if(turn[0]==119)
            	cout<<"白棋輸入落子位置"<<endl;
        	else
            	cout<<"黑棋輸入落子位置"<<endl;
        	cin>>a;
        	if(a==76)
        		break;
        	cin>>y;
        	x=a-64;
        	if(z[x][y]=='@')
        	{
        		for(int i=1;i<=p;i++)
        			for(int j=1;j<=q;j++)
        				if(z[i][j]=='@')
        					z[i][j]='.';//將上一輪提示點移除 
            	for(int i=0;i<=7;i++)
            	{
            		step=1;
                	tx=x+dir[i][0]*step;ty=y+dir[i][1]*step;
                	while(z[tx][ty]==(char)turn[1])
                	{
                    	step+=1;
                    	tx=x+dir[i][0]*step;ty=y+dir[i][1]*step;
                	}
                	if(z[tx][ty]==(char)turn[0]&&step>1)
                		for(int j=0;j<step;j++)
                		{
                   			tx=x+dir[i][0]*j;ty=y+dir[i][1]*j; 
                    		z[tx][ty]=(char)turn[0];
                		}
            	}
				swap(turn[0],turn[1]);
        	}
        	else
            {
            	cout<<"-----------------------"<<endl<<"***這裡無法落子***"<<endl;
            	for(int i=1;i<=p;i++)
        			for(int j=1;j<=q;j++)
        				if(z[i][j]=='@')
        					z[i][j]='.';
			}
        }
        else if(tes==0) 
        {
        	cout<<"沒有地方可下，輪到對方"<<endl;
        	swap(turn[0],turn[1]);
        	det+=1;
		}
        for(int i=1;i<=p;i++)
            for(int j=1;j<=q;j++)
                if(z[i][j]=='.')
                    num+=1;//判斷是否結束
    }
    if(det==2)
    	cout<<"兩方都沒有落子格，提前結束";
    for(int i=1;i<=p;i++)
        for(int j=1;j<=q;j++)
        {
        	if(z[i][j]==w)
        		n1+=1;
        	if(z[i][j]==b)
        		n2+=1;
		}
	cout<<"白子有"<<n1<<"個 "<<"黑子有"<<n2<<"個"<<endl;
	if(n1>n2)
		cout<<"白方勝";
	else if(n1<n2)
		cout<<"黑方勝";
	else
		cout<<"和局";
}
