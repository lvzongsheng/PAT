import java.util.Scanner;
/**
 * 素数对猜想
 * 让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
 * 现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
 * 输入格式：每个测试输入包含1个测试用例，给出正整数N。
 * 输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
 * 输入样例：
 * 	20
 * 输出样例：
 * 	4
 *	
 * Solutions：
 * 如何高效的判断素数，这直接关系到题目的运行超时问题，采用i*i<=n来判断
 * 另外一个是1不是素数，2是素数，能被2整除的数也不是整数。
 * @author lvzongsheng
 *
 */

public class ZH1007 {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		int num = scanner.nextInt();
		int count = 0;
		for(int i=2; i<=num-2; i++){
			if(isSushu(i)&&isSushu(i+2)){
				count++;
			}
		}
		System.out.println(count);
	}
	
	
	public static boolean isSushu(int n){
		if(n < 2) return false;
		if(n == 2) return true;
		if(n%2==0) return false;

		for(int i = 3; i*i <= n; i += 2){
			if(n%i == 0){
				return false;
			}
		}

		return true;
	}
}
