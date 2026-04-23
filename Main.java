import java.util.Scanner;

public class Main {

    // ================= MAP SICKNESS =================
    public static String mapSickness(String input) {
        input = input.toLowerCase();

        if (input.contains("heart")) return "Cardiology";
        if (input.contains("skin")) return "Dermatology";
        if (input.contains("brain")) return "Neurology";
        if (input.contains("child")) return "Pediatrics";
        if (input.contains("bone")) return "Orthopedics";
        if (input.contains("fever") || input.contains("pain")) return "General Medicine";

        return "Unknown";
    }

    // ================= MEETING TIME =================
    public static String generateMeetingTime(String timeSlot, double hours) {
        int start = timeSlot.equalsIgnoreCase("Morning") ? 9 : 13;
        int end = (int)(start + hours);
        return start + ":00 - " + end + ":00";
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // ================= PATIENT =================
        System.out.println("===== PATIENT INFO =====");

        System.out.print("Name: ");
        String name = sc.nextLine();

        System.out.print("Age: ");
        int age = sc.nextInt();
        sc.nextLine();

        System.out.print("Gender: ");
        String gender = sc.nextLine();

        System.out.print("DOB: ");
        String dob = sc.nextLine();

        System.out.print("Phone: ");
        String phone = sc.nextLine();

        Patient patient = new Patient(name, age, gender, dob, phone);

        // ================= DOCTORS =================
        Doctor c1 = new Doctor("Dr. Smith", 45, "Cardiology", 50);
        Doctor c2 = new Doctor("Dr. James", 50, "Cardiology", 55);
        Doctor c3 = new Doctor("Dr. Linda", 39, "Cardiology", 60);

        Doctor d1 = new Doctor("Dr. Anna", 38, "Dermatology", 40);
        Doctor d2 = new Doctor("Dr. Kate", 41, "Dermatology", 45);
        Doctor d3 = new Doctor("Dr. Rose", 37, "Dermatology", 42);

        Doctor n1 = new Doctor("Dr. Lee", 50, "Neurology", 70);
        Doctor n2 = new Doctor("Dr. Omar", 44, "Neurology", 65);
        Doctor n3 = new Doctor("Dr. Chen", 46, "Neurology", 68);

        Doctor p1 = new Doctor("Dr. Kim", 42, "Pediatrics", 45);
        Doctor p2 = new Doctor("Dr. Noor", 36, "Pediatrics", 40);
        Doctor p3 = new Doctor("Dr. Baby", 40, "Pediatrics", 43);

        Doctor o1 = new Doctor("Dr. John", 39, "Orthopedics", 55);
        Doctor o2 = new Doctor("Dr. Paul", 47, "Orthopedics", 60);
        Doctor o3 = new Doctor("Dr. Mark", 45, "Orthopedics", 58);

        Doctor g1 = new Doctor("Dr. Sam", 40, "General Medicine", 30);
        Doctor g2 = new Doctor("Dr. Ali", 35, "General Medicine", 35);
        Doctor g3 = new Doctor("Dr. Maya", 38, "General Medicine", 32);

        // ================= SCHEDULE =================
        Schedule[] schedules = {

            // ===== CARDIOLOGY =====
            new Schedule(c1, "Monday", "Morning", "Room 101"),
            new Schedule(c1, "Wednesday", "Morning", "Room 101"),
            new Schedule(c1, "Friday", "Morning", "Room 101"),

            new Schedule(c2, "Tuesday", "Afternoon", "Room 102"),
            new Schedule(c2, "Thursday", "Afternoon", "Room 102"),

            new Schedule(c3, "Monday", "Afternoon", "Room 103"),
            new Schedule(c3, "Friday", "Afternoon", "Room 103"),

            // ===== DERMATOLOGY =====
            new Schedule(d1, "Monday", "Morning", "Room 201"),
            new Schedule(d1, "Thursday", "Morning", "Room 201"),

            new Schedule(d2, "Tuesday", "Morning", "Room 202"),
            new Schedule(d2, "Friday", "Morning", "Room 202"),

            new Schedule(d3, "Wednesday", "Afternoon", "Room 203"),

            // ===== NEUROLOGY =====
            new Schedule(n1, "Monday", "Morning", "Room 301"),
            new Schedule(n1, "Wednesday", "Afternoon", "Room 301"),

            new Schedule(n2, "Tuesday", "Morning", "Room 302"),
            new Schedule(n2, "Thursday", "Morning", "Room 302"),

            new Schedule(n3, "Friday", "Afternoon", "Room 303"),

            // ===== PEDIATRICS =====
            new Schedule(p1, "Monday", "Morning", "Room 401"),
            new Schedule(p1, "Thursday", "Afternoon", "Room 401"),

            new Schedule(p2, "Tuesday", "Afternoon", "Room 402"),

            new Schedule(p3, "Friday", "Morning", "Room 403"),

            // ===== ORTHOPEDICS =====
            new Schedule(o1, "Monday", "Morning", "Room 501"),
            new Schedule(o1, "Friday", "Morning", "Room 501"),

            new Schedule(o2, "Wednesday", "Afternoon", "Room 502"),

            new Schedule(o3, "Tuesday", "Morning", "Room 503"),

            // ===== GENERAL MEDICINE =====
            new Schedule(g1, "Monday", "Morning", "Room 601"),
            new Schedule(g1, "Thursday", "Morning", "Room 601"),

            new Schedule(g2, "Tuesday", "Afternoon", "Room 602"),
            new Schedule(g2, "Friday", "Afternoon", "Room 602"),

            new Schedule(g3, "Wednesday", "Morning", "Room 603")
        };

        // ================= INPUT =================
        System.out.print("\nEnter sickness (heart/skin/brain/child/bone/fever): ");
        String input = sc.nextLine();

        String department = mapSickness(input);

        if (department.equals("Unknown")) {
            System.out.println("No department found.");
            return;
        }

        System.out.println("\nDepartment: " + department);

        // ================= DISPLAY =================
        System.out.println("\n===== AVAILABLE DOCTORS =====\n");

        Doctor last = null;

        for (Schedule s : schedules) {

            if (s.getDoctor().getSpecialist().equalsIgnoreCase(department)) {

                if (last != s.getDoctor()) {
                    System.out.println("- " + s.getDoctor().getName()
                            + " | $" + s.getDoctor().getHourlyRate() + "/hr");
                    last = s.getDoctor();
                }

                System.out.println("   + " + s.getDay() + " " + s.getTimeSlot()
                        + " | " + s.getRoom());
            }
        }

        // ================= BOOKING =================
        System.out.print("\nEnter day: ");
        String day = sc.nextLine();

        System.out.print("Enter time (Morning/Afternoon): ");
        String time = sc.nextLine();

        Schedule chosen = null;

        for (Schedule s : schedules) {

            if (s.getDoctor().getSpecialist().equalsIgnoreCase(department)
                    && s.getDay().equalsIgnoreCase(day)
                    && s.getTimeSlot().equalsIgnoreCase(time)) {

                chosen = s;
                break;
            }
        }

        if (chosen == null) {
            System.out.println("No doctor available.");
            return;
        }

        System.out.print("Enter consultation hours: ");
        double hours = sc.nextDouble();

        String meetingTime = generateMeetingTime(time, hours);

        Appointment appt = new Appointment("A001", patient, chosen, hours);
        appt.display(meetingTime);

        sc.close();
    }
}