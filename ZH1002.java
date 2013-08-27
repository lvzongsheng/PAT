import java.util.Scanner;
/**
 * 
 * 写出这个数
 * 读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
 * 输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
 * 输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
 * 输入样例：
 * 	1234567890987654321123456789
 * 输出样例：
 * 	yi san wu
 * 
 * @author lvzongsheng
 *
 */

public class ZH1002 {
	static String[] num = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	
	public static void main(String[] args){
		
		Scanner scanner = new Scanner(System.in);
		String input  = scanner.nextLine();
		int sum = 0;
		
		for(int i=0; i<input.length();i++){
			sum+=input.charAt(i)-'0';
		}
		
		print(sum,true);
		
	}
	
	private static void print(int n,boolean isLast){
		if(n==0) return;
		print(n/10,false);
		if(isLast)
			System.out.print(num[n%10]);
		else
			System.out.print(num[n%10]+" ");
	}

}
