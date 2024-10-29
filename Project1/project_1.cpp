#include <iostream> 
#include <cmath> 

bool check_max_score(double max_score) { 
    return (max_score>0 && max_score==(int)max_score); 
}

bool check_score(double score, double max_score) {
    return (score<=max_score && score>=0); 
} 

double calculate_final_mark(double score, double max_score) {
    return 100.0*(score/max_score); 
}

double calculate_mark(double score, double max_score, double final_mark){ 
    double temp_mark; 
    temp_mark=100.0*(score/max_score); 
    if (temp_mark<final_mark) { 
        return final_mark;
    } 
    else { 
        return temp_mark;
    }
}

int main() { 
    double p1_score, p2_score, p3_score, p4_score, p5_score; 
    double p1_max, p2_max, p3_max, p4_max, p5_max;   
    double p1_mark, p2_mark, p3_mark, p4_mark, p5_mark; 
    double project_average; 
    double final_score, final_max; 
    double final_mark; 
    double midterm_score, midterm_max; 
    double midterm_mark; 
    double exam_average; 
    double overall_grade; 
    

    // final exam
    do {
        std::cout << "final exam upper bound: "; 
        std::cin >> final_max;
    } while (!check_max_score(final_max)); 

    do {
        std::cout << "final exam score: "; 
        std::cin >> final_score;
    } while (!check_score(final_score, final_max)); 

    // mid-term exam
    do {
        std::cout << "midterm exam upper bound: "; 
        std::cin >> midterm_max;
    } while (!check_max_score(midterm_max)); 

    do {
        std::cout << "midterm exam score: "; 
        std::cin >> midterm_score;
    } while (!check_score(midterm_score, midterm_max)); 

    // project 1

    do {
        std::cout << "project 1 upper bound: "; 
        std::cin >> p1_max;
    } while (!check_max_score(p1_max)); 

    do {
        std::cout << "project 1 mark: "; 
        std::cin >> p1_score;
    } while (!check_score(p1_score, p1_max)); 

    // project 2 
    do {
        std::cout << "project 2 upper bound: "; 
        std::cin >> p2_max;
    } while (!check_max_score(p2_max)); 

    do {
        std::cout << "project 2 mark: "; 
        std::cin >> p2_score;
    } while (!check_score(p2_score, p2_max));

    // project 3 
    
    do {
        std::cout << "project 3 upper bound: "; 
        std::cin >> p3_max;
    } while (!check_max_score(p3_max)); 

    do {
        std::cout << "project 3 mark: "; 
        std::cin >> p3_score;
    } while (!check_score(p3_score, p3_max));

    // project 4
    do {
        std::cout << "project 4 upper bound: "; 
        std::cin >> p4_max;
    } while (!check_max_score(p4_max)); 

    do {
        std::cout << "project 4 mark: "; 
        std::cin >> p4_score;
    } while (!check_score(p4_score, p4_max));

    // project 5
    do {
        std::cout << "project 5 upper bound: "; 
        std::cin >> p5_max;
    } while (!check_max_score(p5_max)); 

    do {
        std::cout << "project 5 mark: "; 
        std::cin >> p5_score;
    } while (!check_score(p5_score, p5_max));

    final_mark = calculate_final_mark(final_score, final_max); 
    midterm_mark = calculate_mark(midterm_score, midterm_max, final_mark); 
    p1_mark = calculate_mark(p1_score, p1_max, final_mark); 
    p2_mark = calculate_mark(p2_score, p2_max, final_mark); 
    p3_mark = calculate_mark(p3_score, p3_max, final_mark); 
    p4_mark = calculate_mark(p4_score, p4_max, final_mark); 
    p5_mark = calculate_mark(p5_score, p5_max, final_mark); 

    if (midterm_mark<final_mark) {
        midterm_mark=final_mark; 
    }
    if (p1_mark<final_mark) {
        p1_mark=final_mark; 
    }
    if (p2_mark<final_mark) {
        p2_mark=final_mark; 
    }
    if (midterm_mark<final_mark) {
        p3_mark=final_mark; 
    }
    if (midterm_mark<final_mark) {
        p4_mark=final_mark; 
    }
    if (midterm_mark<final_mark) {
        p5_mark=final_mark; 
    }

    //calculate exam average

    exam_average = 0.75*final_mark+0.25*midterm_mark; 
    project_average=(p1_mark+p2_mark+p3_mark+p4_mark+p5_mark)/5; 

    //calculate final
    if (exam_average<=40) {
        overall_grade=exam_average; 
    }
    else if (exam_average>=60) {
        overall_grade=(1.0/2)*final_mark+(1.0/6)*(midterm_mark)+(1.0/3)*(project_average); 
    }
    else {
        overall_grade=(-1.0/60)*exam_average*exam_average + (5.0/3)*exam_average + (1.0/60)*(project_average)*(exam_average)-(2.0/3)*(project_average); 
    }

    overall_grade=std::round(overall_grade+1.0e-12); 
    std::cout << "Final Grade: " << int(overall_grade);
    
    return 0; 
}
 
