import java.util.Scanner;
/**
 * 
 * 成绩排名
 * 读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
 * 输入格式：每个测试输入包含1个测试用例，格式为
 * 第1行：正整数n
 * 第2行：第1个学生的姓名 学号 成绩
 * 第3行：第2个学生的姓名 学号 成绩
 * ... ... ...
 * 第n+1行：第n个学生的姓名 学号 成绩
 * 其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
 * 输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，字符串间有1空格。
 * 输入样例：
 * 	3
 * 	Joe Math990112 89
 * 	Mike CS991301 100
 * 	Mary EE990830 95
 * 输出样例：
 * 	Mike CS991301
 * 	Joe Math990112
 * 
 * 
 * @author lvzongsheng
 *
 */

public class ZH1004 {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String scount = scanner.nextLine();
		int count = Integer.parseInt(scount);		
		String[] name = new String[count];
		Integer[] score = new Integer[count];
		for(int i=0; i<count; i++){
			String input = scanner.nextLine();
			String[] inputs = input.split(" ");
			name[i] = inputs[0]+" "+inputs[1];
			score[i] = Integer.parseInt(inputs[2]);
		}
		
		for(int i=0; i<count-1; i++){
			for(int j=i+1;j>0;j--){
				if(score[j]<score[j-1]){
					int temp = score[j];
					score[j] = score[j-1];
					score[j-1] = temp;
					String te = name[j];
					name[j] = name[j-1];
					name[j-1] = te;
				}
			}
		}
		
		System.out.println(name[count-1]);
		System.out.println(name[0]);
	}
}