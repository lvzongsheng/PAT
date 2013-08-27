import java.util.Scanner;
/**
 * 
 * 换个格式输出整数
 * 让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
 * 输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
 * 输出格式：每个测试用例的输出占一行，用规定的格式输出n。
 * 输入样例1：
 * 	234
 * 输出样例1：
 * 	BBSSS1234
 * 输入样例2：
 * 	23
 * 输出样例2：
 * 	SS123
 * 
 * @author lvzongsheng
 *
 */

public class ZH1006 {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String snum = scanner.nextLine();
		int num = Integer.parseInt(snum);
		int[] count = new int[3];
		for(int i=0; i<3; i++){
			count[i] = num%10;
			num = num/10;
		}
		
		for(int i=2;i>=0;i--){
			for(int j=1; j<=count[i];j++){
				if(i==2){
					System.out.print("B");
				}
				else if(i==1){
					System.out.print("S");
				}
				else{
					System.out.print(j);
				}
			}
		}
	}
	
	
}
