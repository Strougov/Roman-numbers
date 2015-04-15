//////////////////////////////////////////////////////////////////////////
//
//                              РИМСКИЕ ЧИСЛА
//
// Для записи натуральных чисел римскими цифрами используются латинские буквы.
// Каждая буква обозначает десятичное число - имеет вес:
//
// Буква -  Вес
//   I   -    1
//   V   -    5
//   X   -   10
//   L   -   50
//   C   -  100
//   D   -  500
//   M   - 1000
//
// Используя эти буквы, можно записать любое число от 1 до 3999.
// При записи чисел используются следующие правила:
//
// 1. Число, записанное римскими цифрами, читается слева направо.
// 2. Латинские буквы записываются в порядке убывания их весов. 
//    Буквы I, X, С могут быть записаны перед буквами с большими весами:
//    I может предшествовать только буквам V и Х
//    Х может предшествовать только буквам L и С
//    С может предшествовать только буквам D и М.
// 3. Буквы М, С, X, I могут повторяться в записи числа не более трех раз подряд.
//    Все остальные буквы (D, L, V) могут встречаться в записи числа только один раз.
// 4. Числовое значение определяется как сумма весов всех букв, входящих в запись числа.
//    Если буквы I, X, С записаны перед буквами с большими весами, то их веса входят в сумму со знаком минус.
//
// Пример: MMMCMXCIX = 1000+1000+1000+(-100)+1000+(-10)+100+(-1)+10=3999
//
//////////////////////////////////////////////////////////////////////////

#ifndef countof
#define countof(a) (sizeof(a)/sizeof(a[0]))
#endif  countof

CString hsLongToRomane( const long lNum )
{
	CString sTxt;

	if( lNum > 0 && lNum < 4000 )
	{
		long lLog = (long)log10( (double)lNum );
		long lDiv = (long)pow( 10.0, lLog );
		long lKof = lNum / lDiv;
		long lVal = lDiv * ( ( lKof >= 9 ) ? 10 : ( ( lKof >= 4 ) ? 5 : 1 ) );
		long lOne = lDiv * ( ( lKof >= 9 ) ?  9 : ( ( lKof >= 5 ) ? 5 : ( ( lKof >= 4 ) ? 4 : 1 ) ) );

		bool bFlag  = ( lKof != 9 ) && ( lKof != 4 );
		long lLeft  =          bFlag ?    0 : lDiv  ;
		long lRight = lNum - ( bFlag ? lVal : lOne );

		char sLet[] = { "IVXLCDM" };
		int  nIdx   = lLog * 2 + ( ( lKof >= 9 ) ? 2 : ( ( lKof >= 4 ) ? 1 : 0 ) );

		sTxt = hsLongToRomane( lLeft ) + sLet[nIdx] + hsLongToRomane( lRight );
	}

	return sTxt;
}

//////////////////////////////////////////////////////////////////////////

long hsRomaneToLong( const CString & sTxtSrc )
{
	CString sTxt = sTxtSrc;
	sTxt . MakeLower();
	sTxt . Trim();

	long lNum = 0;

	if( !sTxt.IsEmpty() )
	{
		long lVal[] = { 1000, 500, 100,  50,  10,   5,   1 };
		char sChr[] = {  'm', 'd', 'c', 'l', 'x', 'v', 'i' };

		for( size_t t = 0; t < countof(sChr); t++ )
		{
			int pos  = sTxt.Find( sChr[t] );
			if( pos >= 0 )
			{
				CString sLeft  = sTxt.Mid( 0,  pos );
				CString sRight = sTxt.Mid( pos + 1 );

				lNum = lVal[t] + hsRomaneToLong( sRight ) - hsRomaneToLong( sLeft );

				break;
			}
		}
	}

	return lNum;
}

//////////////////////////////////////////////////////////////////////////
