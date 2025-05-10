import java.sql.*;
import java.util.Scanner;

public class BankingManagementSystem {
    public static Connection con = null;
    public static Statement stmt = null;
    public static ResultSet rs = null;
    public static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String url = "jdbc:oracle:thin:@localhost:1521:XE";
        String username = "system";
        String password = "pratik";
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            con = DriverManager.getConnection(url, username, password);
            System.out.println("Database connected successfully!");
            mainMenu();
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("Class Not Found Exception: " + e.getMessage());
        } finally {
            try {
                if (rs != null)
                    rs.close();
                if (stmt != null)
                    stmt.close();
                if (con != null)
                    con.close();
                System.out.println("Connection closed.");
            } catch (SQLException e) {
                System.out.println("Failed to close connection: " + e.getMessage());
            }
        }
    }

    // main menu
    public static void mainMenu() {
        int choice;
        do {
            System.out.println("\n----- Banking Management System -----");
            System.out.println("1. Show Customer Records");
            System.out.println("2. Add Customer Record");
            System.out.println("3. Delete Customer Record");
            System.out.println("4. Update Customer Information");
            System.out.println("5. Show Account Details of a Customer");
            System.out.println("6. Show Loan Details of a Customer");
            System.out.println("7. Deposit Money to an Account");
            System.out.println("8. Withdraw Money from an Account");
            System.out.println("9. Exit the Program");
            System.out.print("Enter your choice (1-9): ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 0:
                    deleteAccount();
                    break;

                case 1:
                    showCustomerRecords();
                    break;

                case 2:
                    addCustomerRecord();
                    break;

                case 3:
                    deleteCustomerRecord();
                    break;

                case 4:
                    updateCustomerRecord();
                    break;

                case 5:
                    showAccountDetails();
                    break;

                case 6:
                    showLoanDetails();
                    break;

                case 7:
                    depositMoney();
                    break;

                case 8:
                    withdrawMoney();
                    break;

                case 9:
                    System.out.println("Exiting the program. Goodbye!");
                    break;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
        } while (choice != 9);
    }

    // show customer records
    public static void showCustomerRecords() {
        try {
            String query = "SELECT * FROM bank_customers";
            stmt = con.createStatement();
            rs = stmt.executeQuery(query);

            if (!rs.isBeforeFirst()) {
                System.out.println("----> No customer records found.");
            } else {
                System.out.println("----> Customer Records:");
                System.out.printf("%-15s %-20s %-15s %-20s%n", "Customer ID", "Name", "Phone Number", "City");
                System.out.println("--------------------------------------------------------------------------");
                while (rs.next()) {
                    System.out.printf("%-15s %-20s %-15s %-20s%n",
                            rs.getString("custno"),
                            rs.getString("name"),
                            rs.getString("phoneno"),
                            rs.getString("city"));
                }
                System.out.println("--------------------------------------------------------------------------");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // add customor record
    public static void addCustomerRecord() {
        System.out.println("----> Add Customer Record");

        String custno = generateCustomerId();
        System.out.print("Enter customer name: ");
        String name = sc.nextLine();
        System.out.print("Enter customer phone number: ");
        String phoneno = sc.nextLine();
        System.out.print("Enter customer address: ");
        String city = sc.nextLine();

        if (name.isEmpty() || phoneno.isEmpty() || city.isEmpty()) {
            System.out.println("----> All fields are required <----");
            return;
        }

        try {
            String query = "INSERT INTO bank_customers VALUES (?, ?, ?, ?)";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, custno);
            pstmt.setString(2, name);
            pstmt.setString(4, phoneno);
            pstmt.setString(3, city);

            int rowsInserted = pstmt.executeUpdate();
            if (rowsInserted > 0) {
                System.out.print(
                        "Do you want to create account for this customer? (Y - to create /N - to skip for now): ");
                String ca = sc.nextLine();
                if (ca.equalsIgnoreCase("Y")) {
                    createAccount(custno);
                } else {
                    System.out.println("----> Customer record added successfully! <----");
                    System.out.println("Your Deatails:");
                    System.out.println("------------------------------------");
                    System.out.println("Customer ID: " + custno);
                    System.out.println("Name: " + name);
                    System.out.println("Phone Number: " + phoneno);
                    System.out.println("City: " + city);
                    System.out.println("------------------------------------");
                }

            } else {
                System.out.println("----> Failed to add customer record <----");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // delete customer record
    public static void deleteCustomerRecord() {
        System.out.print("Enter customer ID to delete: ");
        String custno = sc.nextLine();

        try {
            String query = "DELETE FROM bank_customers WHERE custno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, custno);

            int rowsDeleted = pstmt.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Customer record deleted successfully!");
            } else {
                System.out.println("Failed to delete customer record. Customer ID may not exist.");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // update customer record
    public static void updateCustomerRecord() {
        System.out.print("Enter customer ID to update: ");
        String custno = sc.nextLine();
        if (custno.isEmpty()) {
            System.out.println("----> Customer ID is required <----");
            return;
        }

        while (true) {
            System.out.println("Select the field to update or 0 to go back :");
            System.out.println("1. Name");
            System.out.println("2. Phone Number");
            System.out.println("3. City");
            System.out.print("Enter your choice (1-3): ");
            int fieldChoice = sc.nextInt();
            sc.nextLine();

            String fieldName = null;
            String newValue = null;
            switch (fieldChoice) {
                case 0:
                    return;

                case 1:
                    fieldName = "name";
                    System.out.print("Enter new name: ");
                    newValue = sc.nextLine();
                    break;
                case 2:
                    fieldName = "phoneno";
                    System.out.print("Enter new phone number: ");
                    newValue = sc.nextLine();
                    break;
                case 3:
                    fieldName = "city";
                    System.out.print("Enter new city: ");
                    newValue = sc.nextLine();
                    break;
                default:
                    System.out.println("Invalid choice. No update performed.");
                    return;
            }

            try {
                String query = "UPDATE bank_customers SET " + fieldName + " = ? WHERE custno = ?";
                PreparedStatement pstmt = con.prepareStatement(query);
                pstmt.setString(1, newValue);
                pstmt.setString(2, custno);

                int rowsUpdated = pstmt.executeUpdate();
                if (rowsUpdated > 0) {
                    System.out.println("Customer record updated successfully!");
                } else {
                    System.out.println("Failed to update customer record. Customer ID may not exist.");
                }
            } catch (SQLException e) {
                System.out.println("SQL Exception: " + e.getMessage());
            }
        }
    }

    // show loan details of a customer
    public static void showLoanDetails() {
        System.out.print("Enter customer ID to view loan details: ");
        String custno = sc.nextLine();

        try {
            String query = "SELECT l.custno, l.loanno, l.loanamount, l.interestrate, l.startdate, l.enddate, " +
               "(l.enddate - l.startdate) AS loan_duration, b.branchcode, b.branchname, b.branchcity " +
               "FROM bank_loan l " +
               "JOIN bank_branch b ON l.branchcode = b.branchcode " +
               "WHERE l.custno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, custno);
            rs = pstmt.executeQuery();

            if (!rs.isBeforeFirst()) {
            System.out.println("----> No loan details found for the given customer ID.");
            } else {
            System.out.println("----> Loan Details:");
            System.out.printf("%-15s %-15s %-15s %-15s %-15s %-15s %-20s%n", 
                      "Customer ID", "Loan No", "Loan Amount", "Interest Rate", 
                      "Loan Duration", "Branch Code", "Branch Name", "Branch City");
            System.out.println("---------------------------------------------------------------------------------------------");
            while (rs.next()) {
                System.out.printf("%-15s %-15s %-15.2f %-15.2f %-15d %-15s %-20s %-20s%n",
                    rs.getString("custno"),
                    rs.getString("loanno"),
                    rs.getDouble("loanamount"),
                    rs.getDouble("interestrate"),
                    rs.getInt("loan_duration"),
                    rs.getString("branchcode"),
                    rs.getString("branchname"),
                    rs.getString("branchcity"));
            }
            System.out.println("---------------------------------------------------------------------------------------------");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // create account
    public static void createAccount(String custno) {
        if (custno == null) {
            System.out.print("Enter customer ID to create account: ");
            custno = sc.nextLine();
        }

        String accno = generateAccountId();
        System.out.print("Enter account type (C - Current/ S- Saving): ");
        String acctype = sc.nextLine();

        if (!acctype.equalsIgnoreCase("C") && !acctype.equalsIgnoreCase("S")) {
            System.out.println("----> Invalid account type <----");
            return;
        } else if (acctype.equalsIgnoreCase("C")) {
            acctype = "current";
        } else if (acctype.equalsIgnoreCase("S")) {
            acctype = "saving";
        }

        System.out.print("Enter initial deposit amount: ");
        double balance = sc.nextDouble();
        sc.nextLine();
        if (balance < 0) {
            System.out.println("----> Invalid balance amount <----");
            return;
        }

        System.out.print("Enter branch code: ");
        String branchCode = sc.nextLine();

        System.out.println("----> Creating Account:");

        try {
            String query = "INSERT INTO bank_account VALUES (?, ?, ?, ?, ?)";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, accno);
            pstmt.setString(2, custno);
            pstmt.setString(3, acctype);
            pstmt.setDouble(4, balance);
            pstmt.setString(5, branchCode);

            int rowsInserted = pstmt.executeUpdate();
            if (rowsInserted > 0) {
                System.out.println("----> Account created successfully! <----");
                System.out.println("Your Account Details:");
                System.out.println("------------------------------------");
                System.out.println("Account Number: " + accno);
                System.out.println("Customer ID: " + custno);
                System.out.println("Account Type: " + acctype);
                System.out.println("Balance: " + balance);
                System.out.println("------------------------------------");
            } else {
                System.out.println("----> Failed to create account <----");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // delete account
    public static void deleteAccount() {
        System.out.print("Enter account number to delete: ");
        String accno = sc.nextLine();

        try {
            String query = "DELETE FROM bank_account WHERE accno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, accno);

            int rowsDeleted = pstmt.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("Account deleted successfully!");
            } else {
                System.out.println("Failed to delete account. Account number may not exist.");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // show account details of a customer
    public static void showAccountDetails() {
        System.out.print("Enter customer ID to view account details: ");
        String custno = sc.nextLine();

        try {
            String query = "SELECT c.custno, c.name, c.phoneno, c.city, a.accno, a.acctype, a.balance, b.branchcode, b.branchname, b.branchcity "
                    +
                    "FROM bank_customers c " +
                    "JOIN bank_account a ON c.custno = a.custno " +
                    "JOIN bank_branch b ON a.branchcode = b.branchcode " +
                    "WHERE c.custno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, custno);
            rs = pstmt.executeQuery();

            if (!rs.isBeforeFirst()) {
                System.out.println("----> No account details found for the given customer ID.");
            } else {
                System.out.println("----> Account Details:");
                System.out.printf("%-15s %-20s %-15s %-20s %-15s %-15s %-15s %-15s %-20s%n",
                        "Customer ID", "Name", "Phone Number", "City", "Account Number", "Account Type", "Balance",
                        "Branch Code", "Branch Name");
                System.out.println(
                        "---------------------------------------------------------------------------------------------------------------");
                while (rs.next()) {
                    System.out.printf("%-15s %-20s %-15s %-20s %-15s %-15s %-15.2f %-15s %-20s%n",
                            rs.getString("custno"),
                            rs.getString("name"),
                            rs.getString("phoneno"),
                            rs.getString("city"),
                            rs.getString("accno"),
                            rs.getString("acctype"),
                            rs.getDouble("balance"),
                            rs.getString("branchcode"),
                            rs.getString("branchname"));
                }
                System.out.println(
                        "---------------------------------------------------------------------------------------------------------------");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // deposit money to an account
    public static void depositMoney() {
        System.out.print("Enter account number to deposit money: ");
        String accno = sc.nextLine();
        System.out.print("Enter amount to deposit: ");
        double amount = sc.nextDouble();
        sc.nextLine();

        if (amount <= 0) {
            System.out.println("----> Invalid deposit amount <----");
            return;
        }

        try {
            String query = "UPDATE bank_account SET balance = balance + ? WHERE accno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setDouble(1, amount);
            pstmt.setString(2, accno);

            int rowsUpdated = pstmt.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Deposit successful! New balance updated.");
                System.out.println("Balance: " + getAccountBalance(accno));
            } else {
                System.out.println("Failed to deposit money. Account number may not exist.");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // get account balance
    public static double getAccountBalance(String accno) {
        double balance = 0.0;
        try {
            String query = "SELECT balance FROM bank_account WHERE accno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setString(1, accno);
            rs = pstmt.executeQuery();
            if (rs.next()) {
                balance = rs.getDouble("balance");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
        return balance;
    }

    // withdraw money from an account
    public static void withdrawMoney() {
        System.out.print("Enter account number to withdraw money: ");
        String accno = sc.nextLine();
        System.out.print("Enter amount to withdraw: ");
        double amount = sc.nextDouble();
        sc.nextLine();

        if (amount <= 0) {
            System.out.println("----> Invalid withdrawal amount <----");
            return;
        }

        try {
            String query = "UPDATE bank_account SET balance = balance - ? WHERE accno = ?";
            PreparedStatement pstmt = con.prepareStatement(query);
            pstmt.setDouble(1, amount);
            pstmt.setString(2, accno);

            int rowsUpdated = pstmt.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("Withdrawal successful! New balance updated.");
                System.out.println("Balance: " + getAccountBalance(accno));
            } else {
                System.out.println("Failed to withdraw money. Account number may not exist.");
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
    }

    // generate customer ID
    public static String generateCustomerId() {
        String custno = null;
        try {
            String query = "SELECT MAX(custno) FROM bank_customers";
            stmt = con.createStatement();
            rs = stmt.executeQuery(query);
            if (rs.next() && rs.getString(1) != null) {
                String maxAccno = rs.getString(1);
                String max = maxAccno.substring(1, maxAccno.length());
                custno = keyNumber("C", max);
            } else {
                custno = "C00001";
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
        return custno;
    }

    // generate account ID
    public static String generateAccountId() {
        String accno = null;
        try {
            String query = "SELECT MAX(accno) FROM bank_account";
            stmt = con.createStatement();
            rs = stmt.executeQuery(query);
            if (rs.next() && rs.getString(1) != null) {
                String maxAccno = rs.getString(1);
                String max = maxAccno.substring(1, maxAccno.length());
                accno = keyNumber("A", max);
            } else {
                accno = "A00001";
            }
        } catch (SQLException e) {
            System.out.println("SQL Exception: " + e.getMessage());
        }
        return accno;
    }

    // generate key number
    public static String keyNumber(String s, String maxNo) {
        int num = Integer.parseInt(maxNo) + 1;
        int zeroC = maxNo.length() - String.valueOf(num).length();
        for (int i = 0; i < zeroC; i++) {
            s += "0";
        }
        return s + num;
    }

}

/*

(1)
Database connected successfully!

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 1
----> Customer Records:
Customer ID     Name                 Phone Number    City
--------------------------------------------------------------------------
C0001           RAHUL SHARMA         9876543210      DELHI
C0002           PRIYA PATEL          8765432109      MUMBAI
C0003           AMIT KUMAR           7654321098      BANGALORE
C0004           NEHA GUPTA           6543210987      HYDERABAD
C0005           VIJAY SINGH          5432109876      CHENNAI
C0006           ANITA DESAI          4321098765      KOLKATA
C0007           SANJAY MEHTA         3210987654      PUNE
C0008           MEERA JOSHI          2109876543      AHMEDABAD
C0009           RAVI VERMA           1098765432      JAIPUR
C0010           SUNITA REDDY         9988776655      BHUBANESWAR
--------------------------------------------------------------------------



(2)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 2
----> Add Customer Record
Enter customer name: ANWESHA DAS
Enter customer phone number: 9999999999
Enter customer address: BHUBANESWAR
Do you want to create account for this customer? (Y - to create /N - to skip for now): N
----> Customer record added successfully! <----
Your Deatails:
------------------------------------
Customer ID: C0011
Name: ANWESHA DAS
Phone Number: 9999999999
City: BHUBANESWAR
------------------------------------

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 2
----> Add Customer Record
Enter customer name: SACHIN SINGH
Enter customer phone number: 989898989
Enter customer address: CUTTACK
Do you want to create account for this customer? (Y - to create /N - to skip for now): N
----> Customer record added successfully! <----
Your Deatails:
------------------------------------
Customer ID: C0012
Name: SACHIN SINGH
Phone Number: 989898989
City: CUTTACK
------------------------------------

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 2
----> Add Customer Record
Enter customer name: ARJUN MISHRA
Enter customer phone number: 7777777777
Enter customer address: BHUBANESWAR
Do you want to create account for this customer? (Y - to create /N - to skip for now): N
----> Customer record added successfully! <----
Your Deatails:
------------------------------------
Customer ID: C0013
Name: ARJUN MISHRA
Phone Number: 7777777777
City: BHUBANESWAR
------------------------------------



(3)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 3
Enter customer ID to delete: C0013
Customer record deleted successfully!

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 3
Enter customer ID to delete: C0016
Failed to delete customer record. Customer ID may not exist.



(4)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 4
Enter customer ID to update: C0011
Select the field to update or 0 to go back :
1. Name
2. Phone Number
3. City
Enter your choice (1-3): 1
Enter new name: ANWESHA DASH
Customer record updated successfully!
Select the field to update or 0 to go back :
1. Name
2. Phone Number
3. City
Enter your choice (1-3): 2
Enter new phone number: 7001234568
Customer record updated successfully!
Select the field to update or 0 to go back :
1. Name
2. Phone Number
3. City
Enter your choice (1-3): 3
Enter new city: CUTTACK
Customer record updated successfully!
Select the field to update or 0 to go back :
1. Name
2. Phone Number
3. City
Enter your choice (1-3): 0



(5)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 5
Enter customer ID to view account details: C0003
----> Account Details:
Customer ID     Name                 Phone Number    City                 Account Number  Account Type    Balance         Branch Code     Branch Name
---------------------------------------------------------------------------------------------------------------
C0003           AMIT KUMAR           7654321098      BANGALORE            A0003           SAVINGS         75000.00        B003            SOUTH BRANCH
---------------------------------------------------------------------------------------------------------------

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 5
Enter customer ID to view account details: C0005
----> Account Details:
Customer ID     Name                 Phone Number    City                 Account Number  Account Type    Balance         Branch Code     Branch Name
---------------------------------------------------------------------------------------------------------------
C0005           VIJAY SINGH          5432109876      CHENNAI              A0005           SAVINGS         30000.00        B005            EASTERN BRANCH
---------------------------------------------------------------------------------------------------------------

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 5
Enter customer ID to view account details: C0016
----> No account details found for the given customer ID.



(6)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 6
Enter customer ID to view loan details: C0003
----> Loan Details:
Customer ID     Loan No         Loan Amount     Interest Rate   Loan Duration   Branch Code     Branch Name
---------------------------------------------------------------------------------------------
C0003           L0002           200000.00       7.00            1826            B003            SOUTH BRANCH         BANGALORE
---------------------------------------------------------------------------------------------

Enter customer ID to view loan details: C0003
----> Loan Details:
Customer ID     Loan No         Loan Amount     Interest Rate   Loan Duration   Branch Code     Branch Name
---------------------------------------------------------------------------------------------
C0003           L0002           200000.00       7.00            1826            B003            SOUTH BRANCH         BANGALORE
---------------------------------------------------------------------------------------------

Enter customer ID to view loan details: C0005
----> Loan Details:
Customer ID     Loan No         Loan Amount     Interest Rate   Loan Duration   Branch Code     Branch Name
---------------------------------------------------------------------------------------------
C0005           L0003           300000.00       10.00           1096            B005            EASTERN BRANCH       CHENNAI             
---------------------------------------------------------------------------------------------

Enter customer ID to view loan details: C0008
----> Loan Details:
Customer ID     Loan No         Loan Amount     Interest Rate   Loan Duration   Branch Code     Branch Name
---------------------------------------------------------------------------------------------
C0008           L0004           400000.00       12.00           1826            B002            WESTERN BRANCH       MUMBAI
---------------------------------------------------------------------------------------------

Enter customer ID to view loan details: C0016
----> No loan details found for the given customer ID.



(7)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 7
Enter account number to deposit money: A0008
Enter amount to deposit: 800
Deposit successful! New balance updated.
Balance: 80800.0

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 7
Enter account number to deposit money: A0005
Enter amount to deposit: 10000
Deposit successful! New balance updated.
Balance: 40000.0



(8)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 8    
Enter account number to withdraw money: A0008
Enter amount to withdraw: 800
Withdrawal successful! New balance updated.
Balance: 80000.0

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 8
Enter account number to withdraw money: A0008
Enter amount to withdraw: 8000
Withdrawal successful! New balance updated.
Balance: 72000.0

----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 8
Enter account number to withdraw money: A0005
Enter amount to withdraw: 10000
Withdrawal successful! New balance updated.
Balance: 30000.0



(9)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 9
Exiting the program. Goodbye!
Connection closed.



(10)
----- Banking Management System -----
1. Show Customer Records
2. Add Customer Record
3. Delete Customer Record
4. Update Customer Information
5. Show Account Details of a Customer
6. Show Loan Details of a Customer
7. Deposit Money to an Account
8. Withdraw Money from an Account
9. Exit the Program
Enter your choice (1-9): 10
Invalid choice. Please try again.

*/