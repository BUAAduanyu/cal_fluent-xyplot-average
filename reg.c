#include <stdio.h>
#include <math.h> 
void main()
{
   FILE *fp;
   double x[5000] = {0};	//定义一个数组，用于存放5000个变量.
   char buffer[1024] = {0}; //定义一个buffer，用于存放临时存放文件中每行的数据.
   double y[5000] = {0};  //用于存放5000个变量的数值.
   int i=0,j = 0;
   int shuzushu;
   fp = fopen( "D:\\file.txt", "r" );
   if( !fp )
   {
      getchar();
      printf( "File open fail." ); //文件打开失败，提示错误，然后直接返回.
   }
   else
   {
      while( !feof(fp) && i<5000 ) //判断文件是否结束，且只读取文件的5000行数据.
      {
         fgets( buffer, 1024, fp  ); //获取每一行的数据存放到buffer中.
         sscanf( buffer, "%lf\t%lf", &x[i], &y[i] ); //流式字符串格式化输入，sscanf: stream scan format,用法和scanf一样.
         i++;
      }
    shuzushu = i;
	/*
	for( j=0; j<shuzushu; j++ )
  	{
    	printf( "%.5f\t%.10f\n", x[j], y[j] ); //输出从文件读取的信息.
   	}
   	测试输出*/ 
	}
   //getchar();
   //开始排序
    for (i = 0; i < shuzushu-1; i++)  //只需要比较length-1次，比如3个数相比 只需要比较2次 
    {  
        for (j = 0; j < shuzushu-i-1; j++)  //每次都能找到最小的数，因此可以将其排除，条件即变为：j<length-i-1  
        {  
            if (x[j] > x[j+1])  //交换  
            {  
                double temp = x[j];  
                x[j] = x[j+1];  
                x[j+1] = temp;
                temp = y[j];
                y[j] = y[j+1];  
                y[j+1] = temp;
            }  
        }  
    }
	/*
	for( j=0; j < shuzushu; j++ )
  	{
    	printf( "%.5f\t%.10f\n", x[j], y[j] ); //输出从文件读取的信息.
   	} 
   	测试输出*/ 
   	//开始求平均
	int check[5000]={0};     //检查过的数据做个标记 
	int    checknum=0;         //检查过的数目 
	double  cx[5000]={0};   //没重复的x值 
	double  py[5000]={0};   //对应y平均值 
	int    yn[5000]={0};   //同x值的个数 
	
	int    cn=0;          //无重复的x个数 
	double   sum=0;
	double   count=0;
	for(i=0;i<shuzushu;i++)
	{
    if(1-check[i])
    {
        check[i]=1;
        sum=y[i];
        count=1;
        cx[cn]=x[i];
        checknum++;
        for(j=i+1;j<shuzushu;j++)
        {
            if(x[i]==x[j])
            {
                sum+=y[j];
                count++;
                check[j]=1;
                checknum++;
                yn[cn]++;
            }
        }
        py[cn]=sum/count;
        cn++;
    }
    if(checknum>=shuzushu) break;
	} 
   	for( j=0; j < cn; j++ )
  	{
    	printf( "%.5f\t%.10f\n", cx[j], py[j] ); //输出从文件读取的信息.
   	}
   	//输出到文件
	FILE *fpp=fopen("d:\\reg_average.txt","w");
	fprintf( fpp,"Position\tReg\n");
	fprintf( fpp,"m\tm/s\n\n\n");
	for( j=0; j<cn; j++ )
   	{
      fprintf( fpp,"%.5f\t%.10f\n", cx[j], py[j]); //输出从文件读取的信息.
   	}
 	fclose(fpp);
 	getchar(); 
}
