/**
 * C/C++����ʮ�������ַ������
 * @Filename:  hexstrxor.c
 * @author  :  vfhky  2014.11.09  https://typecodes.com/cseries/hexstrxor.html
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

//ASCII���н��ַ�ת���ɶ�Ӧ��ʮ������
int char2int( char input )
{
    return input>64?(input-55):(input-48);
}

//ASCII���н�ʮ������ת���ɶ�Ӧ���ַ�
int int2char( char input )
{
    return input>9?(input+55):(input+48);
}

//��ʮ�������ַ���HexStr1��HexStr2���õ�HexStr
void hexstrxor( char * HexStr1, char * HexStr2, char * HexStr )
{
    int i, iHexStr1Len, iHexStr2Len, iHexStrLenLow, iHexStrLenGap;

    //ת���ɴ�д���󳤶�
    strupr( HexStr1 );
    strupr( HexStr2 );
    iHexStr1Len = strlen( HexStr1 );
    iHexStr2Len = strlen( HexStr2 );

    //��ȡ��С�ĳ���
    iHexStrLenLow = iHexStr1Len<iHexStr2Len?iHexStr1Len:iHexStr2Len;

    //��ȡ���Ȳ�ֵ
    iHexStrLenGap = abs( iHexStr1Len-iHexStr2Len );

    //����ʮ�����Ƶ��ַ����������
    for( i=0; i<iHexStrLenLow; i++ )
    {
        *(HexStr+i) = char2int( HexStr1[i] ) ^ char2int( HexStr2[i] );
        *(HexStr+i) = int2char( *(HexStr+i) );
    }
    if( iHexStr1Len>iHexStr2Len )
        memcpy( HexStr+i, HexStr1+i, iHexStrLenGap );
    else if( iHexStr1Len<iHexStr2Len )
        memcpy( HexStr+i, HexStr2+i, iHexStrLenGap );
    *( HexStr+iHexStrLenLow+iHexStrLenGap ) = 0x00;
}


int main( int argc, char * argv[] )
{
    //����ʮ�����Ƶ��ַ����Լ����Ľ��result
    
    
    
    while(1)
	{	
		char *HexStr1 = new char[50];
	    char *HexStr2 = new char[50];
		char result[17] = {0};
    	scanf("%s",HexStr1);
		scanf("%s",HexStr2);
	
	    //������򷽷�
	    hexstrxor( HexStr1, HexStr2, result );
	    //��ӡ�����
	    printf( "\nresult=[%s]\n", result );
	}
	

    return 0;
}
