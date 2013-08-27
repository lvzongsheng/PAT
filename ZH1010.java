import java.util.ArrayList;
import java.util.Scanner;
/**
 * 
 * 一元多项式求导
 * 设计函数求一元多项式的导数。
 * 输入格式：以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
 * 输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。
 * 输入样例：
 * 	3 4 -5 2 6 1 -2 0
 * 输出样例：
 * 	12 3 -10 1 6 0
 * 
 * Solutions:
 * 这个题目要注意的是当输出为空应该输出0 0
 * 另外一个输入直接用nextInt
 * 在使用split(" ")的时候要防止出现多个空格的出现
 * @author lvzongsheng
 *
 */

public class ZH1010 {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> result = new ArrayList<Integer>();
		while(scanner.hasNextInt()){
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			if(b!=0){
					result.add(a*b);
					result.add(b-1);
			}
		}
		
		if(result.size()==0){
			System.out.print(0+" "+0);
			return;
		}
		for(int i=0; i<result.size();i=i+2){
			if(i>0)
				System.out.print(" ");
			System.out.print(result.get(i)+" "+result.get(i+1));
		}
	}
}
