//sarah tarek gouda fouda 18104349
//nadia fahmy medra 18101664

package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        String[] address = new String[100];
        address[0] = "7";
        //73 without to dec ..  //10  System.out.println(hexToDec(address[0]) + 3);
        // a  System.out.println(decToHex(hexToDec(address[0]) + 3));
        splitFile();
    }

    public static String decToHex(int dec) {
        return Integer.toHexString(dec);
    }

    private static int hexToDec(String hex) {
        return Integer.parseInt(hex, 16);
    }

    public static void splitFile() throws FileNotFoundException {

        String[] label = new String[100];
        String[] instruction = new String[100];
        String[] reference = new String[100];
        String[] symbols = new String[100];
        String[] address = new String[100];
        String[] addresstable = new String[100];
        String[] objectcode = new String[100];
        String[] code = new String[100];
        final String[][] OPTAB = new String[59][3];

        OPTAB[0] = new String[]{"FIX", "1", "C4"};
        OPTAB[1] = new String[]{"FLOAT", "1", "C0"};
        OPTAB[2] = new String[]{"HIO", "1", "F4"};
        OPTAB[3] = new String[]{"NORM", "1", "C8"};
        OPTAB[4] = new String[]{"SIO", "1", "F0"};
        OPTAB[5] = new String[]{"TIO", "1", "F8"};
        OPTAB[6] = new String[]{"ADDR", "2", "90"};
        OPTAB[7] = new String[]{"CLEAR", "2", "B4"};
        OPTAB[8] = new String[]{"COMPR", "2", "A0"};
        OPTAB[9] = new String[]{"DIVR", "2", "9C"};
        OPTAB[10] = new String[]{"MULR", "2", "98"};
        OPTAB[11] = new String[]{"RMO", "2", "AC"};
        OPTAB[12] = new String[]{"SHIFTL", "2", "A4"};
        OPTAB[13] = new String[]{"SHIFTR", "2", "A8"};
        OPTAB[14] = new String[]{"SUBR", "2", "94"};
        OPTAB[15] = new String[]{"SVC", "2", "B0"};
        OPTAB[16] = new String[]{"TIXR", "2", "B8"};
        OPTAB[17] = new String[]{"ADD", "3", "18"};
        OPTAB[18] = new String[]{"ADDF", "3", "58"};
        OPTAB[19] = new String[]{"AND", "3", "40"};
        OPTAB[20] = new String[]{"COMP", "3", "28"};
        OPTAB[21] = new String[]{"COMPF", "3", "88"};
        OPTAB[22] = new String[]{"DIV", "3", "24"};
        OPTAB[23] = new String[]{"DIVF", "3", "64"};
        OPTAB[24] = new String[]{"J", "3", "3C"};
        OPTAB[25] = new String[]{"JEQ", "3", "30"};
        OPTAB[26] = new String[]{"JGT", "3", "34"};
        OPTAB[27] = new String[]{"JLT", "3", "38"};
        OPTAB[28] = new String[]{"JSUB", "3", "48"};
        OPTAB[29] = new String[]{"LDA", "3", "00"};
        OPTAB[30] = new String[]{"LDB", "3", "68"};
        OPTAB[31] = new String[]{"LDCH", "3", "50"};
        OPTAB[32] = new String[]{"LDF", "3", "70"};
        OPTAB[33] = new String[]{"LDL", "3", "08"};
        OPTAB[34] = new String[]{"LDS", "3", "6C"};
        OPTAB[35] = new String[]{"LDT", "3", "74"};
        OPTAB[36] = new String[]{"LDX", "3", "04"};
        OPTAB[37] = new String[]{"LPS", "3", "D0"};
        OPTAB[38] = new String[]{"MUL", "3", "20"};
        OPTAB[39] = new String[]{"MULF", "3", "60"};
        OPTAB[40] = new String[]{"OR", "3", "44"};
        OPTAB[41] = new String[]{"RD", "3", "D8"};
        OPTAB[42] = new String[]{"RSUB", "3", "4C"};
        OPTAB[43] = new String[]{"SSK", "3", "EC"};
        OPTAB[44] = new String[]{"STA", "3", "0C"};
        OPTAB[45] = new String[]{"STB", "3", "78"};
        OPTAB[46] = new String[]{"STCH", "3", "54"};
        OPTAB[47] = new String[]{"STF", "3", "80"};
        OPTAB[48] = new String[]{"STI", "3", "D4"};
        OPTAB[49] = new String[]{"STL", "3", "14"};
        OPTAB[50] = new String[]{"STS", "3", "7C"};
        OPTAB[51] = new String[]{"STSW", "3", "E8"};
        OPTAB[52] = new String[]{"STT", "3", "84"};
        OPTAB[53] = new String[]{"STX", "3", "10"};
        OPTAB[54] = new String[]{"SUB", "3", "1C"};
        OPTAB[55] = new String[]{"SUBF", "3", "5C"};
        OPTAB[56] = new String[]{"TD", "3", "E0"};
        OPTAB[57] = new String[]{"TIX", "3", "2C"};
        OPTAB[58] = new String[]{"WD", "3", "DC"};

        int r = 0;

        try {

            File file = new File("Assemblyyy.txt");
            if (!file.exists()) {
                System.out.println("File doesn't Exist");
                return;
            }

            Scanner scan = new Scanner(file);
            while (scan.hasNextLine()) {

// to split what so ever spaces or tapes
                int x = 0;
                String l = scan.nextLine();
                String[] tl = new String[3];
                String[] line = l.split("\\s+");
                boolean flag = false;

                for (int i = 0; i < line.length; i++) {
                    if (line[i].isEmpty()) {
                        if (i == 0) {
                            flag = true;
                        }
                    } else {
                        tl[x] = line[i];
                        x++;
                    }
                }
                if (x == 3) {
                    label[r] = tl[0];
                    instruction[r] = tl[1];
                    reference[r] = tl[2];
                } else if (x == 2 && flag == true) {
                    label[r] = ("#");
                    instruction[r] = tl[0];
                    reference[r] = tl[1];
                } else if (x == 2 && flag == false) {
                    label[r] = tl[0];
                    instruction[r] = tl[1];
                    reference[r] = "#";
                } else if (x == 1) {
                    label[r] = "#";
                    instruction[r] = tl[0];
                    reference[r] = "#";
                }
                r++;
            }
////////////////////////////////////////////////location counter
            for (int j = 1; j < r; j++) {

                if (j == 0 || j == 1) {
                    address[0] = reference[0];
                    address[1] = reference[0];
                }

                if (!instruction[j].equalsIgnoreCase("WORD") && !instruction[j].equalsIgnoreCase("RESW") && !instruction[j].equalsIgnoreCase("RESB") && !instruction[j].equalsIgnoreCase("BYTE")) {
                    address[j + 1] = decToHex(hexToDec(address[j]) + 3);

                } else if (instruction[j].equalsIgnoreCase("RESW")) {
                    address[j + 1] = decToHex((Integer.parseInt(reference[j]) * 3) + hexToDec(address[j]));
                    objectcode[j] = " No Object Code";

                } else if (instruction[j].equalsIgnoreCase("RESB")) {
                    address[j + 1] = decToHex((Integer.parseInt(reference[j])) + hexToDec(address[j]));
                    objectcode[j] = " No Object Code";

                } else if (instruction[j].trim().equalsIgnoreCase("BYTE")) {
                    if (reference[j].startsWith("C")) {
                        address[j + 1] = decToHex(hexToDec(address[j]) + reference[j].length() - 3);
                        objectcode[j] = calculate( ascii(reference[j]),6,'0');
                    }
                    if (reference[j].startsWith("X")) {
                        address[j + 1] = decToHex(hexToDec(address[j]) + (reference[j].length() - 3)/2);
                        objectcode[j] = calculate( xoc(reference[j]),6,'0');
                    }
                }
                if (instruction[j].equalsIgnoreCase("WORD")) {
                    if (reference[j].contains(",")) {
                        String[] count = reference[j].split(",");
                        int length = count.length;
                        address[j + 1] = decToHex(hexToDec(address[j]) + (length * 3));
                    } else {
                        address[j + 1] = decToHex(hexToDec(address[j]) + 3);
                    }
                }
            }
/////////////////////////////////////////////////////////////////

            for (int a = 0; a < r; a++) {
                for (int s = 0; s < OPTAB.length; s++) {
                    if (instruction[a].trim().equalsIgnoreCase(OPTAB[s][0].trim())) {
                        if (reference[a].contains(",")) {
                            String arr[] = reference[a].split(",");
                            for (int k = 0; k < reference.length; k++) {
                                if (arr[0].trim().equalsIgnoreCase(label[k])) {
                                    code[a] = decToHex(hexToDec(address[k]) + (hexToDec("8000") * 1));
                                    break;
                                }
                            }
                        } else {
                            for (int k = 0; k < label.length; k++) {

                                // this is for trace
                                // System.out.println(reference[a]+"   "+label[k]);
                                // you need to compare it with the labels as symboltable is empty you
                                // didn't use it
                                if (reference[a].trim().equalsIgnoreCase(label[k])) {

                                    // this is for trace
                                    // System.out.println("iffffffff "+reference[a]+"   "+label[k]+"  "+address[k]);
                                    // code[a]+=sybmolTable...
                                    // code[a] is = null so when you add on it it will be null+something
                                    // sybmoltable you didn't use it so it is empty
                                    code[a] = address[k];

                                    break;
                                }
                            }
                        }
                        objectcode[a] = OPTAB[s][2];
                        // add to the object code the address of the refernce which is strored in
                        // code
                        objectcode[a] += code[a];
                    } else if (instruction[a].trim().equalsIgnoreCase("WORD")) {
                        if (reference[a].contains(",")) {
                            String[] arr = reference[a].split(",");
                            for (int j = 0; j < arr.length; j++) {
                                objectcode[a] = Integer.toHexString(Integer.parseInt(arr[a]));
                                objectcode[a] = calculate(objectcode[a], 6, '0');
                                break;
                            }
                        } else {
                            objectcode[a] = Integer.toHexString(Integer.parseInt(reference[a]));
                            objectcode[a] = calculate(objectcode[a], 6, '0');
                        }
                    }
                }
            }
            int index = 0;

            for (int i = 0; i < r; i++) {
                if (!label[i].contains("#")) {
                    symbols[index] = label[i];
                    addresstable[index] = address[i];
                    index++;
                }
            }
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        print(label, instruction, reference, symbols, address, addresstable, objectcode, code,r);

    }

    public static void print(String label[], String instruction[], String reference[], String symbols[], String address[], String addresstable[], String objectcode[], String code[], int r) {
        Scanner scanner = new Scanner(System.in);

        while (true) {

            System.out.println("Choose a number:-");
            System.out.println("1)  print Labels");
            System.out.println("2)  print Instructions");
            System.out.println("3)  print Reference");
            System.out.println("4)  print Symbols");
            System.out.println("5)  print location counter");
            System.out.println("6)  print Symbol Table");
            System.out.println("7)  print Pass One");
            System.out.println("8)  print pass two");
            System.out.println("9)  print Object Code");
            System.out.println("10)  print HTE record");
            System.out.println("11) To Exit");
            System.out.print("Enter Your Choice :- ");

            int num = scanner.nextInt();

            switch (num) {

                case 1:
                    sendPrint(label, r );
                    break;

                case 2:
                    sendPrint(instruction, r );
                    break;

                case 3:
                    sendPrint(reference, r );
                    break;

                case 4:
                    sendPrint(symbols, r );
                    break;

                case 5:
                    sendPrint(address, r );
                    break;

                case 6:
                    System.out.println("-------------------------");
                    System.out.println("| instruction | address |");
                    System.out.println("-------------------------");
                    for (int i = 1; i < r; i++) {
                        if (symbols[i] != null) {
                            System.out.println("|  " + calculate(symbols[i].trim(), 8, ' ') + "|" + calculate(addresstable[i].trim(), 8, ' ') + "    |");
                        }
                    }
                    System.out.println("-------------------------");
                    break;

                case 7:
                    System.out.println("-----------------------------------------------------");
                    System.out.println("|location counter |lable   |instruction | reference |");
                    System.out.println("-----------------------------------------------------");
                    int n = instruction.length;
                    for (int i = 1; i < n; i++) {
                        if (instruction[i] != null) {
                            System.out.print('|');
                            System.out.print(calculate(address[i].trim(), 17, ' ') + "|" + calculate(label[i].trim(), 8, ' ') + "|" + calculate(instruction[i].trim(), 12, ' ') + "|" + calculate(reference[i].trim(), 8, ' '));
                            System.out.println("   |");
                        }
                    }
                    System.out.println("-----------------------------------------------------");
                    break;
                case 8:
                    System.out.println("----------------------------------------------------------------------");
                    System.out.println("|location counter |lable   |instruction | reference | object code    |");
                    System.out.println("----------------------------------------------------------------------");
                    int b = objectcode.length;
                    for (int i = 1; i < b-1; i++) {
                        if (objectcode[i] != null) {
                            System.out.print('|');
                            System.out.print(calculate(address[i].trim(), 16, ' ') + " |" + calculate(label[i].trim(), 7, ' ') + " |" + calculate(instruction[i].trim(), 11, ' ') + " |" + calculate(reference[i].trim(), 10, ' ')+ " | " + calculate( calculate(objectcode[i].trim(), 6, '0'),14,' '));
                            System.out.println(" |");
                        }
                    }
                    System.out.println("----------------------------------------------------------------------");
                    break;
                case 9:
                    sendPrint(objectcode, r );
                    break;

                case 10:
                    int i = 0,
                            z = 1,
                            j = 0;
                    while (address[i] != null) {
                        i++;
                    }
                    System.out.print("H ^ " + calculate(label[0], 6, '0') + " ^ " + calculate(reference[0], 6, '0') + " ^ " + calculate(decToHex(hexToDec(address[i - 1]) - hexToDec(reference[0])), 6, '0'));
                    while (z < i) {
                        j = z;
                        if (objectcode[z] != " No Object Code" && objectcode[z] != null && z <= j + 10) {
                            System.out.println(" ");
                            String send = address[z];
                            System.out.print("T ^ " + calculate(address[z], 6, '0') + " ^ " + calculate(distance(i, z, j, objectcode, send, address), 2, '0') + " ^ ");
                        }

                        for (int c = 0; c < 10; c++) {
                            if (objectcode[z] != " No Object Code" && objectcode[z] != null) {
                                System.out.print(calculate(objectcode[z], 6, '0') + " ");
                                z++;
                            } else {
                                z++;
                                break;
                            }
                        }

                    }
                    System.out.println(" ");
                    System.out.println("E ^ " + calculate(reference[0], 6, '0'));
                    System.out.println(" ");
                    break;

                case 11:
                    return;

                default:
                    System.out.println("Error , plz try again !!");
                    break;

            }
        }
    }

    public static void sendPrint(String print[],int r) {
        for (int i = 0; i < r; i++) {
            if (print[i] != null) {
                System.out.println(print[i].trim());
            }
        }
        System.out.println("--------------------------------------------");
    }

    public static String calculate(String v, int x, char w) {
        int c = v.length();
        int add;
        add = x - c;
        String r = "";
        for (int i = 0; i < add; i++) {
            r = r + w;
        }
        r = r + v;
        return r;
    }

    public static String distance(int i, int z, int j, String objectcode[], String send, String address[]) {
        String sub = "";
        j = z;
        for (int c = 0; c < 10; c++) {
            if (objectcode[z + 1] != " No Object Code" && objectcode[z + 1] != null) {
                z++;
            } else {
                z++;
                break;
            }
        }
        sub = decToHex(hexToDec(address[z]) - hexToDec(send));
        return sub;
    }

    public static String ascii(String ref) {
        String oc = "";
        for (int i = 2; i < ref.length() - 1; i++) {
            char c = ref.charAt(i);
            int a = (int) c;
            oc = oc + decToHex(a);
        }
        return oc;
    }

    public static String xoc(String ref) {
        String oc = "";
        char[] ch = new char[ref.length()];
        for (int i = 0; i < ref.length(); i++) {
            ch[i] = ref.charAt(i);
        }
        for (int i = 2; i < ref.length() - 1; i++) {
            oc = oc + String.valueOf(ch[i]);
        }
        return oc;
    }
}