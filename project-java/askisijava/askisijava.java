package askisijava;

import java.io.*;  
import java.util.Scanner; 


import spaces.*;
import people.*;
import people.student.*; 

public class askisijava {

    public static void main(String[] args)  { 
        
        // το μέγεθος των τάξεων
        int capacity_class = Integer.parseInt(args[0]);

        // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός junior
        int Lj = Integer.parseInt(args[1]);

        // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός senior
        int Ls = Integer.parseInt(args[2]);

        // οι μονάδες που αυξάνεται ανά ώρα ο βαθμός κούρασης ενός teacher
        int Lt = Integer.parseInt(args[3]);

        // οι ώρες που λειτουργεί το σχολείο
        int N = Integer.parseInt(args[4]);

        // δημιουργία του σχολείου
        school s = new school(capacity_class);

        try{

            // προσπέλαση του αρχείου γραμμή γραμμή
            // και μέτρηση του αριθμόυ των μαθητών και των δασκάλων
            // που θέλουν να μπουν στο σχολείο
            ///////////////////////////////////////////////////////////////////////////////////////////
            String teacher_or_student;
            
            int count_students = 0;
            int count_teachers = 0;

            BufferedReader reader = new BufferedReader(new FileReader("/home/iliasliakos/oop/programs/askisijava/file.txt"));
            String line = reader.readLine();
            
            while (line != null) {

                String[] dataParts = line.split(" ");
                
                teacher_or_student =  dataParts[0];

                if(teacher_or_student.equals("s")){

                    count_students++;
                }
                else{

                    count_teachers++;
                }
                
                line = reader.readLine();
            }
            ///////////////////////////////////////////////////////////////////////////////////

            // δημιουργία πινάκων μαθητών και δασκάλων
            student[] array_of_students = new student[count_students];
            teacher[] array_of_teachers = new teacher[count_teachers];

            String name;
            int floor_no;
            int class_no;

            BufferedReader reader2 = new BufferedReader(new FileReader("/home/iliasliakos/oop/programs/askisijava/file.txt"));
            String line2 = reader2.readLine();
            
            int i = 0;
            int y = 0;

            // προσπέλαση του αρχείου γραμμή γραμμή
            while (line2 != null) {

                String[] dataParts2 = line2.split(" "); 
                
                teacher_or_student =  dataParts2[0];
                name = dataParts2[1];
                floor_no = Integer.parseInt(dataParts2[2]);
                class_no = Integer.parseInt(dataParts2[3]);

                // αν είναι μαθητής
                if(teacher_or_student.equals("s")){

                    // αν είναι junior
                    if(class_no <= 3){

                        // δημιουργία junior
                        array_of_students[i] = new junior(name, floor_no, class_no, Lj);
                    }
                    // αν είναι senior
                    else{

                        // δημιουργία senior
                        array_of_students[i] = new junior(name, floor_no, class_no, Ls);
                    }

                    i++;               
                }
                // αν είναι δάσκαλος
                else{

                    // δημιουργία δασκάλου
                    array_of_teachers[y] = new teacher(name, floor_no, class_no, Lt);

                    y++;
                }
                
                // διάβασμα επόμενης γραμμής
                line2 = reader2.readLine();
            }


            // κλήση της enter της school για κάθε μαθητή
            for(int z = 0; z < count_students; z++){

                s.enter(array_of_students[z]);
            }

            // κλήση της place της school για κάθε καθηγητή
            for(int k = 0; k < count_teachers; k++){

                s.place(array_of_teachers[k]);
            }
    

            // κλήση της operate της school 
            s.operate(N);

            // εκτύπωση του σχολείου
            s.print();

            // άδειασμα του σχολείου
            s.empty();

            s.print();
        }  
        catch(Exception e)  
        {  
            
            e.printStackTrace();  
        }  
    } 
}