import java.util.Scanner;
public class main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        //enter an account data;
        System.out.print("enter the account holder name: ");
        String name = scanner.nextLine();
        System.out.print("enter the account holder balance: ");
        double balance = scanner.nextDouble();
        BankAccount account= new BankAccount(name, balance);
        boolean valid = true;
        while(valid){
            System.out.println("-------BANK MENU-------"); 
            System.out.println("1: Check the balance"); 
            System.out.println("2: Deposite money"); 
            System.out.println("3: Withdraw money"); 
            System.out.println("4: EXIST"); 
            System.out.println("choose an option (enter a number 1-4)");
            int choice = scanner.nextInt();
            double amount;
            switch(choice){
                case 1: account.seeBalance(); break;
                case 2: System.out.print("enter the deposit amount: ");
                amount = scanner.nextDouble();
                account.deposit(amount);
                break;
                case 3: System.out.print("enter the withdraw amount: ");
                amount = scanner.nextDouble();
                account.withdraw(amount);
                break;
                case 4: System.out.println("thank you for your service");
                valid = false;
                break;
                default: System.out.println("enter a valid choice");
            }
        }
        scanner.close();
    }
}