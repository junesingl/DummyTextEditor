# include "Text Head.h"

///////////////////////////////////////////////////////////////////////////////////
//	Main Function

void main()
{
	char Option;

	printf("-");

	while(1)
	{
		scanf("%c",&Option);

		if(Option=='o')
			Open();
		else if(Option=='h')
			Help();
		else if(Option=='s')
			Save();
		else if(Option=='f')
			Find();
		else if(Option=='r')
			Replace();
		else if(Option=='d')
			Delete();
		else if(Option=='q')
		{	
			Quit();
			break;
		}
	}

	return;
}
