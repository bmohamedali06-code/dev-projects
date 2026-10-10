public class BankAccount{
    String accountHolder;
    private double balance;
    //consulter to initialize account data
    BankAccount(String name, double initialBalance){
        this.accountHolder = name;
        this.balance = initialBalance;
    }
    //method to see the balance
    public void seeBalance(){
        System.out.printf("your balance is :%.3f \n", balance);
    }
    //method to desposit money
    public void deposit(double money){
        if(money <= 0)
            System.out.println("the money amount is invalid(amount must be a non zero positive number)");
        else{
            System.out.println("amount added successfully");
            balance += money;
        }
    }
    //method to withdraw money
    public void withdraw(double money){
        if(money <= 0)
            System.out.println("the money amount is invalid(amount must be a non zero positive number)");
        else if(money > balance)
            System.out.println("insufficient balance");
        else{
            System.out.println("the amount withdraw successfully");
            balance -= money;
        }
    }
}