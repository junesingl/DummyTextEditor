# include "Text Head.h"

///////////////////////////////////////////////////////////////////////////////////
//	Function

void Open()										//Œƒº˛¥Úø™≤Ÿ◊˜∫Ø ˝
{
	char temp;

	scanf("%c");
	scanf("%s",Filename);

	if((fps=fopen(Filename,"r+"))!=NULL)
	{
		while(!feof(fps))
			printf("%c",fgetc(fps));
	}
	else
		printf("File open error!\n");

	rewind(fps);

	printf("\n-");
}

void Help()										//∞Ô÷˙–≈œ¢∫Ø ˝
{
	printf("** Helping Information **\n");

	printf("\n-");
}

void Save()										//Œƒº˛±£¥Ê≤Ÿ◊˜∫Ø ˝
{
	char temp;

	scanf("%c");
	scanf("%s",Filename);

	if((fclose(fps))&&((fps=fopen(Filename,"r+"))==NULL))
		printf("Can not save the file!\n");

	printf("\n-");
}

void Find()										//◊÷∑˚¥Æ≤È’“∫Ø ˝
{	
	SqString s;									//¥”Œƒº˛÷–∂¡≥ˆµƒ◊÷∑˚¥Æ
	SqString t;									//”√ªß ‰»Îµƒπÿº¸◊÷¥Æ
	char temp;
	int counter=0;								//’“µΩπÿº¸◊÷¥Œ ˝
	int i=0,flag=0;
	
	s.length=0;
	t.length=0;

	scanf("%c");
	scanf("%c",&temp);							//∂¡»°πÿº¸◊÷
	while(temp!='\n')
	{
		t.data[i]=temp;
		t.length++;
		i++;
		scanf("%c",&temp);
	}
	t.data[i]='\0';

//	printf("%s\n",t.data);

	i=0;
	while(!feof(fps))							//∂¡»°Œƒº˛
	{
		s.data[i]=fgetc(fps);
		s.length++;
		i++;
	}
	s.data[i-1]='\0';
	rewind(fps);
	
//	printf("%s\n",s.data);
	
	while(flag!=-1)								//≤È’“≤Ÿ◊˜
	{
		flag=KMPIndex(s,t);
		if (flag>=0)
		{
			counter++;				
			
			for(i=0;flag+t.length+i<=s.length;i++)
			{
				s.data[i]=s.data[flag+t.length+i+1];
			}
			s.data[flag+i]='\0';
			
			s.length=s.length-flag-t.length-1;
		}
	}
	
	printf("%d\n",counter);						//œ‘ æ≤È’“≥…π¶¥Œ ˝
	
	if((fpr=fopen("1252930_result.txt","a+"))==NULL)	//¥Úø™/¥¥Ω®1252930_result.txt
		fpr=fopen("1252930_result.txt","w+");
	fprintf(fpr,"-f %s %d\n",t.data,counter);	//Ω´≤È’“≥…π¶¥Œ ˝–¥»Î1252930_result.txt
	
	if(fclose(fpr))								//±£¥Ê≤¢πÿ±’1252930_result.txt
		printf("Can not close the file!\n");

	printf("\n-");
}

void Replace()									//◊÷∑˚¥ÆÃÊªª∫Ø ˝
{
	SqString s;									//¥”Œƒº˛÷–∂¡≥ˆµƒ◊÷∑˚¥Æ
	SqString t;									//±ªÃÊªªµƒπÿº¸◊÷¥Æ
	SqString r;									//–¬µƒπÿº¸◊÷¥Æ
	char temp;
	int counter=0;								//’“µΩπÿº¸◊÷¥Œ ˝
	int i=0,j=0,flag=0;
	
	s.length=0;
	t.length=0;
	r.length=0;

	scanf("%c");
	scanf("%c",&temp);							//∂¡»°±ªÃÊªªµƒπÿº¸◊÷¥Æ
	while(temp!=' ')
	{
		t.data[i]=temp;
		t.length++;
		i++;
		scanf("%c",&temp);
	}
	t.data[i]='\0';

//	printf("%s\n",t.data);

	scanf("%c",&temp);							//∂¡»°–¬µƒπÿº¸◊÷¥Æ
	i=0;	
	while(temp!='\n')
	{
		r.data[i]=temp;
		r.length++;
		i++;
		scanf("%c",&temp);
	}
	r.data[i]='\0';

//	printf("%s\n",r.data);					

	i=0;
	while(!feof(fps))							//∂¡»°Œƒº˛
	{
		s.data[i]=fgetc(fps);
		s.length++;
		i++;
	}
	s.data[i-1]='\0';
	rewind(fps);
	
	
	while(flag!=-1)								//ÃÊªª≤Ÿ◊˜
	{
		flag=KMPIndex(s,t);
		if (flag>=0)
		{
			counter++;				
			
			if(t.length>r.length)
			{
				for(i=flag+r.length;i<=s.length-t.length+r.length;i++)
				{
					s.data[i]=s.data[i+t.length-r.length];
				}
				s.data[i+1]='\0';
				
				s.length=s.length-t.length+r.length;
				
				for(i=flag,j=0;j<r.length;i++,j++)
				{
					s.data[i]=r.data[j];
				}
			}
			else if(t.length<r.length)
			{
				for(i=s.length-t.length+r.length;i>=flag+r.length;i--)
				{
					s.data[i]=s.data[i+t.length-r.length];
				}
				s.data[s.length-t.length+r.length+1]='\0';
				
				s.length=s.length-t.length+r.length;
				
				for(i=flag,j=0;j<r.length;i++,j++)
				{
					s.data[i]=r.data[j];
				}
			}
			else if(t.length==r.length)
			{
				for(i=flag,j=0;j<r.length;i++,j++)
				{
					s.data[i]=r.data[j];
				}
			}
		}
	}
	
	printf("%d\n",counter);						//œ‘ æÃÊªª¥Œ ˝
	printf("%s\n",s.data);						//œ‘ æÃÊªªπÿº¸◊÷π˝∫Ûµƒ¿¥‘¥Œƒº˛
	
	fprintf(fps,"%s",s.data);					//Ω´ÃÊªªπÿº¸◊÷∫Ûµƒ◊÷∂Œ–¥»Î¿¥‘¥Œƒº˛
	rewind(fps);
	
	if((fpr=fopen("1252930_result.txt","a+"))==NULL)	//¥Úø™/¥¥Ω®1252930_result.txt
		fpr=fopen("1252930_result.txt","w+");
	fprintf(fpr,"-r %s %s %d\n",t.data,r.data,counter);		//Ω´ÃÊªª¥Œ ˝–¥»Î1252930_result.txt
	fprintf(fpr,"%s\n",s.data);					//Ω´ÃÊªªπÿº¸◊÷∫Ûµƒ◊÷∂Œ–¥»Î1252930_result.txt
	
	if(fclose(fpr))								//±£¥Ê≤¢πÿ±’1252930_result.txt
		printf("Can not close the file!\n");

	printf("\n-");
}

void Delete()									//◊÷∑˚¥Æ…æ≥˝∫Ø ˝
{
	SqString s;									//¥”Œƒº˛÷–∂¡≥ˆµƒ◊÷∑˚¥Æ
	SqString t;									//”√ªß ‰»Îµƒπÿº¸◊÷¥Æ
	char temp;
	int counter=0;								//’“µΩπÿº¸◊÷¥Œ ˝
	int i=0,flag=0;
	
	s.length=0;
	t.length=0;

	scanf("%c");
	scanf("%c",&temp);							//∂¡»°πÿº¸◊÷
	while(temp!='\n')
	{
		t.data[i]=temp;
		t.length++;
		i++;
		scanf("%c",&temp);
	}
	t.data[i]='\0';

//	printf("%s\n",t.data);

	i=0;
	while(!feof(fps))							//∂¡»°Œƒº˛
	{
		s.data[i]=fgetc(fps);
		s.length++;
		i++;
	}
	s.data[i-1]='\0';
	rewind(fps);
	
//	printf("%s\n",s.data);
	
	while(flag!=-1)								//…æ≥˝≤Ÿ◊˜
	{
		flag=KMPIndex(s,t);
		if (flag>=0)
		{
			counter++;				
			
			for(i=flag;i<=s.length-t.length;i++)
			{
				s.data[i]=s.data[t.length+i+1];
			}
			s.data[i+1]='\0';
			
			s.length=s.length-t.length-1;
		}
	}
	
	printf("%d\n",counter);						//œ‘ æ…æ≥˝¥Œ ˝
	printf("%s\n",s.data);						//œ‘ æ…æ≥˝πÿº¸◊÷∫Ûµƒ¿¥‘¥Œƒº˛
	
	fprintf(fps,"%s",s.data);					//Ω´…æ≥˝πÿº¸◊÷∫Ûµƒ◊÷∂Œ–¥»Î¿¥‘¥Œƒº˛
	rewind(fps);
	
	if((fpr=fopen("1252930_result.txt","a+"))==NULL)	//¥Úø™/¥¥Ω®1252930_result.txt
		fpr=fopen("1252930_result.txt","w+");
	fprintf(fpr,"-d %s %d\n",t.data,counter);		//Ω´…æ≥˝¥Œ ˝–¥»Î1252930_result.txt
	fprintf(fpr,"%s\n",s.data);					//Ω´…æ≥˝πÿº¸◊÷∫Ûµƒ◊÷∂Œ–¥»Î1252930_result.txt
	
	if(fclose(fpr))								//±£¥Ê≤¢πÿ±’1252930_result.txt
		printf("Can not close the file!\n");

	printf("\n-");
}

void Quit()										//ÕÀ≥ˆ∫Ø ˝
{
	if(fclose(fps))
		printf("Can not close the file!\n");
}

void GetNext(SqString t,int next[])				//KMPIndex()µƒ∏®÷˙∫Ø ˝
{
	int j,k;
	
	j=0;
	k=-1;
	next[0]=-1;

	while(j<t.length-1)
	{
		if(k==-1||t.data[j]==t.data[k])
		{
			j++;
			k++;
			next[j]=k;
		}
		else
			k=next[k];
	}
}

int KMPIndex(SqString s,SqString t)				//”√”⁄±»Ωœµƒ∫Ø ˝£¨∑µªÿ∆•≈‰ ◊◊÷∑˚Œª÷√
{
	int next[MaxSize],i=0,j=0;
	
	GetNext(t,next);
	while(i<s.length && j<t.length)
	{
		if(j==-1||s.data[i]==t.data[j])
		{
			i++;
			j++;
		}
		else j=next[j];
	}
	if(j>=t.length)
		return(i-t.length);
	else
		return(-1);
}
