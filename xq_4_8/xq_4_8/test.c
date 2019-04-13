//void reverse(char *start, char *end)
//{
//	//assert(start);
//	//assert(end);
//	while (start < end)
//	{
//		*start ^= *end;
//		*end ^= *start;
//		*start ^= *end;
//		start++, end--;
//	}
//}
//void reversestring(char *mag)
//{
//	//assert(mag);
//	char *p = mag;
//	char *q = mag;
//	while (*q){
//		if (isspace(*q))
//		{
//			reverse(p, q - 1);
//			q++;
//			p = q;
//		}
//		q++;
//	}
//	reverse(p, q - 1);
//	reverse(mag, q - 1);
//}
//int main()
//{
//	char mag[] = "student a am i";
//	reversestring(mag);
//	printf("%s\n", mag);
//	system("pause");
//	return 0;
//}
