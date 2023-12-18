#include <stdio.h>
#include <string.h>

struct NgaySinh {
    int date;
    int month;
    int year;
};
struct Diem {
	float toan ;
	float van ;
	float anh ;
	float   tbc ;
	};

struct SinhVien {
    int maSV;
    char hoTen[30];
    struct NgaySinh ngaySinh;
    char gioiTinh[10];
    struct Diem diem;
    char sdt[10];
    char lop[10];
};

void hienThiCot(){
printf("%-20s %-20s %-15s %-20s %-15s %-10s \n", 
		"Ma SV","ten","sinh ngay", "Gioi Tinh", 
		"phone","lop");}


void HienThiDanhSachSV(struct SinhVien ArrSinhVien[], int slgSV) {
    printf("=====================================\n");

	hienThiCot();
    for (int i = 0; i < slgSV; i++) {
        printf("%-20d %-20s %d\\%d\\%d       %-20s %-15s %-10s\n", 
		ArrSinhVien[i].maSV,
		ArrSinhVien[i].hoTen,
        ArrSinhVien[i].ngaySinh.date,
		 ArrSinhVien[i].ngaySinh.month,
		  ArrSinhVien[i].ngaySinh.year,
		  
               ArrSinhVien[i].gioiTinh,
			    ArrSinhVien[i].sdt,
				 ArrSinhVien[i].lop);
    }
}

void HienThiDanhSachSVTheoLop(struct SinhVien ArrSinhVien[], int slgSV, char lop[30]) {
    printf("Hien thi danh sach sinh vien theo lop\n");
    hienThiCot();
    for (int i = 0; i < slgSV; i++) {
        if (strcmp(lop, ArrSinhVien[i].lop) == 0) {
            printf("%-20d %-20s %d\\%d\\%d       %-20s %-15s %-10s\n",  ArrSinhVien[i].maSV, ArrSinhVien[i].hoTen,
                   ArrSinhVien[i].ngaySinh.date, ArrSinhVien[i].ngaySinh.month, ArrSinhVien[i].ngaySinh.year,
                   ArrSinhVien[i].gioiTinh, ArrSinhVien[i].sdt, ArrSinhVien[i].lop);
        }
    }
}

void TimKiemSinhVienTheoMa(struct SinhVien ArrSinhVien[], int slgSV, int ma) {
    printf("Tim kiem sinh vien theo ma sinh vien\n");
    hienThiCot();
    
    for (int i = 0; i < slgSV; i++) {
        if (ArrSinhVien[i].maSV == ma) {
            printf("%-20d %-20s %d\\%d\\%d       %-20s %-15s %-10s\n",  ArrSinhVien[i].maSV, ArrSinhVien[i].hoTen,
                   ArrSinhVien[i].ngaySinh.date, ArrSinhVien[i].ngaySinh.month, ArrSinhVien[i].ngaySinh.year,
                   ArrSinhVien[i].gioiTinh, ArrSinhVien[i].sdt, ArrSinhVien[i].lop);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ma %d\n", ma);
}

void HienThiDiem(struct SinhVien ArrSinhVien[], int slgSV) {
    printf("Hien thi diem sinh vien\n");
    printf("%-20s %-20s %-15s %-20s %-15s %-10s\n","Ma SV","ten","toan","anh","van","tbc");
    for (int i = 0; i < slgSV; i++) {
printf("%-20d %-20s %-15.2f %-20.2f %-15.2f %-15.2f\n ",
	ArrSinhVien[i].maSV,
	ArrSinhVien[i].hoTen,
    ArrSinhVien[i].diem.toan,
	ArrSinhVien[i].diem.van,
	ArrSinhVien[i].diem.anh,
	ArrSinhVien[i].diem.tbc);
    }
}
void NhapDiem(struct SinhVien ArrSinhVien[], int slgSV) {
    int ma;
    printf("Nhap vao ma sinh vien can nhap diem: ");
    scanf("%d", &ma);

    for (int i = 0; i < slgSV; i++) {
        if (ArrSinhVien[i].maSV == ma) {
            printf("Nhap diem cho sinh vien %s (Ma SV: %d)\n", ArrSinhVien[i].hoTen, ArrSinhVien[i].maSV);
            printf("Nhap diem Toan: ");
            scanf("%f", &ArrSinhVien[i].diem.toan);
            printf("Nhap diem Van: ");
            scanf("%f", &ArrSinhVien[i].diem.van);
            printf("Nhap diem Anh: ");
            scanf("%f", &ArrSinhVien[i].diem.anh);
            ArrSinhVien[i].diem.tbc = (ArrSinhVien[i].diem.toan+ArrSinhVien[i].diem.van+ArrSinhVien[i].diem.anh)/3;
            printf("Nhap diem thanh cong!\n");
            
            return;
        }
    }

    printf("Khong tim thay sinh vien co ma %d\n", ma);
}


void NhapSinhVien(struct SinhVien ArrSinhVien[], int *slgSV) {
    printf("Nhap thong tin cho ban sinh vien thu %d\n", *slgSV + 1);
    printf("Nhap vao ma sinh vien: ");
    scanf("%d", &ArrSinhVien[*slgSV].maSV);
    printf("Nhap vao ho va ten sinh vien: ");
    fflush(stdin);
    gets(ArrSinhVien[*slgSV].hoTen);
    printf("Nhap vao ngay: ");
    scanf("%d", &ArrSinhVien[*slgSV].ngaySinh.date);
    printf("Nhap vao thang: ");
    scanf("%d", &ArrSinhVien[*slgSV].ngaySinh.month);
    printf("Nhap vao nam: ");
    scanf("%d", &ArrSinhVien[*slgSV].ngaySinh.year);
    printf("Nhap vao gioi tinh ");
    fflush(stdin);
    gets(ArrSinhVien[*slgSV].gioiTinh);
    printf("Nhap vao sdt sinh vien: ");
    fflush(stdin);
    gets(ArrSinhVien[*slgSV].sdt);
    printf("Nhap vao lop sinh vien: ");
    fflush(stdin);
    gets(ArrSinhVien[*slgSV].lop);
    (*slgSV)++;
}

void CapNhatSinhVien(struct SinhVien ArrSinhVien[], int slgSV, int ma) {
    for (int i = 0; i < slgSV; i++) {
        if (ArrSinhVien[i].maSV == ma) {
            printf("Nhap thong tin cho sinh vien co ma %d\n", ma);
            printf("Nhap vao ho va ten sinh vien: ");
            fflush(stdin);
            gets(ArrSinhVien[i].hoTen);
            printf("Nhap vao ngay: ");
            scanf("%d", &ArrSinhVien[i].ngaySinh.date);
            printf("Nhap vao thang: ");
            scanf("%d", &ArrSinhVien[i].ngaySinh.month);
            printf("Nhap vao nam: ");
            scanf("%d", &ArrSinhVien[i].ngaySinh.year);
            printf("Nhap vao gioi tinh sinh vien: ");
            fflush(stdin);
            gets(ArrSinhVien[i].gioiTinh);
            printf("Nhap vao sdt sinh vien: ");
            fflush(stdin);
            gets(ArrSinhVien[i].sdt);
            printf("Nhap vao lop sinh vien: ");
            fflush(stdin);
            gets(ArrSinhVien[i].lop);
            printf("Cap nhat thong tin thanh cong!\n");
            return;
        }
    }
printf("Khong tim thay sinh vien co ma %d\n", ma);
}
void capNhatDiem(struct SinhVien ArrSinhVien[], int slgSV, int ma)
{for (int i = 0; i < slgSV; i++) {
        if (ArrSinhVien[i].maSV == ma) {
            printf("Nhap diem cho sinh vien co ma %d\n", ma);
			printf("nhap diem toan");
			scanf("%f",&ArrSinhVien[i].diem.toan);
			printf("nhap diem van");
			scanf("%f",&ArrSinhVien[i].diem.van);
			printf("nhap diem toan");
			scanf("%f",&ArrSinhVien[i].diem.anh);
			printf("cap nhat diem thanh cong");
			ArrSinhVien[i].diem.tbc = (ArrSinhVien[i].diem.toan+ArrSinhVien[i].diem.van+ArrSinhVien[i].diem.anh)/3;
	        printf("Nhap diem thanh cong!\n");
			return;

           }
    }
printf("Khong tim thay sinh vien co ma %d\n", ma);
}
void TbcMaxMin(struct SinhVien ArrSinhVien[], int slgSV) {
    float max = ArrSinhVien[0].diem.tbc;
    float min = ArrSinhVien[0].diem.tbc;
    int sv_max = 0;
    int sv_min = 0;

    for (int i = 1; i < slgSV; i++) {
        if (min > ArrSinhVien[i].diem.tbc) {
            min = ArrSinhVien[i].diem.tbc;
            sv_min = i;
        }
        if (max < ArrSinhVien[i].diem.tbc) {
            max = ArrSinhVien[i].diem.tbc;
            sv_max = i;
        }
    }

    printf("Sinh vien co diem trung binh cao nhat la: %s (Ma SV: %d)\n",
           ArrSinhVien[sv_max].hoTen, ArrSinhVien[sv_max].maSV);
    printf("Diem trung binh: %.2f\n", ArrSinhVien[sv_max].diem.tbc);

    printf("Sinh vien co diem trung binh thap nhat la: %s (Ma SV: %d)\n",
           ArrSinhVien[sv_min].hoTen, ArrSinhVien[sv_min].maSV);
    printf("Diem trung binh: %.2f\n", ArrSinhVien[sv_min].diem.tbc);
}

void TongTBC(struct SinhVien ArrSinhVien[], int slgSV) {
    float sum = 0;
    printf("TBC cac hoc sinh la:\n");

    for (int i = 0; i < slgSV; i++) {
        sum += ArrSinhVien[i].diem.tbc;
    }

    float arv = sum / slgSV;

    printf("TBC ca lop la: %f\n", arv);
   
}
void XoaSinhVien(struct SinhVien ArrSinhVien[], int *slgSV, int ma) {
    for (int i = 0; i < *slgSV; i++) {
        if (ArrSinhVien[i].maSV == ma) {
            for (int j = i; j < *slgSV - 1; j++) {
                ArrSinhVien[j] = ArrSinhVien[j + 1];
            }
            (*slgSV)--;
            printf("Xoa sinh vien co ma %d thanh cong!\n", ma);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ma %d\n", ma);
}

void SapXepTheoHoTen(struct SinhVien ArrSinhVien[], int slgSV) {
    

    for (int i = 0; i < slgSV - 1; i++) {
        for (int j = 0; j < slgSV - i - 1; j++) {
            if (strcmp(ArrSinhVien[j].hoTen, ArrSinhVien[j + 1].hoTen) > 0) {
                
                struct SinhVien temp = ArrSinhVien[j];
                ArrSinhVien[j] = ArrSinhVien[j + 1];
                ArrSinhVien[j + 1] = temp;
            }
        }
    }

    printf("Sap xep thanh cong!\n");
}

void SapXepTheoDiemTB(struct SinhVien ArrSinhVien[], int soluongSV) {
    for (int i = 0; i < soluongSV - 1; i++) {
        for (int j = 0; j < soluongSV - i - 1; j++) {
            if (ArrSinhVien[j].diem.tbc < ArrSinhVien[j + 1].diem.tbc) {
                struct SinhVien temp = ArrSinhVien[j];
                ArrSinhVien[j] = ArrSinhVien[j + 1];
                ArrSinhVien[j + 1] = temp;
            }
        }
    }

    printf("Danh sach sinh vien sau khi sap xep theo diem trung binh:\n");
  
  
}
int main() {
    int chon = 0;
    struct SinhVien ArrSinhVien[1000];
    int slgSV = 0;
    int chonQuanLySinhVien = 0;
    int ma;
	char lop[30];
	char ten[30];
    int chonQuanLyDiem = 0;
    float sum;
    float arv;
    do {
        printf("*********** MENU CHINH *************\n");
        printf("1. Quan li sinh vien\n");
        printf("2. Quan li diem\n");
        printf("0. Thoat\n");
        printf("Moi nhap vao lua chon cua ban: ");
        scanf("%d", &chon);
        switch (chon) {
            case 0:
                printf("Ban da thoat khoi chuong trinh\n");
                break;

            case 1:
				do {
                    printf("********** MENU QUAN LY SINH VIEN ************\n");
                    printf("1. Hien thi danh sach sinh vien\n");
                    printf("2. Nhap thong tin sinh vien\n");
                    printf("3. Cap nhat thong tin sinh vien\n");
                    printf("4. Xoa sinh vien\n");
                    printf("5. sap xep  sinh vien theo ten \n");
                    printf("6. Tim kiem sinh vien theo lop sinh vien\n");
                    printf("7. tim kiem sinh vien theo ma ");
                    printf("0. Thoat\n");
                    printf("Moi nhap vao lua chon cua ban: ");
                    scanf("%d", &chonQuanLySinhVien);
                    switch (chonQuanLySinhVien) {
                        
                        case 1:
                            HienThiDanhSachSV(ArrSinhVien, slgSV);
                            printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
						break;
                        case 2:
                            NhapSinhVien(ArrSinhVien, &slgSV);
                        break;
                        case 3:
                            printf("Nhap vao ma sinh vien can cap nhat: ");
                            scanf("%d", &ma);
                            CapNhatSinhVien(ArrSinhVien, slgSV, ma);
                        break;
                        case 4:  
                            printf("Nhap vao ma sinh vien can xoa: ");
                            scanf("%d", &ma);
                            XoaSinhVien(ArrSinhVien, &slgSV, ma);
                        break;                   
                        case 5:
                            SapXepTheoHoTen(ArrSinhVien, slgSV);
                        break;
                        case 6:                         
                            printf("Nhap vao lop can hien thi danh sach sinh vien: ");
                            fflush(stdin);
                            gets(lop);
                            HienThiDanhSachSVTheoLop(ArrSinhVien, slgSV, lop);
                    	break;
                        case 7:                         
                            printf("Nhap vao ma sinh vien can tim kiem: \n");
                            scanf("%d", &ma);
                            TimKiemSinhVienTheoMa(ArrSinhVien, slgSV, ma);
                        break;    
						case 0:
                            printf("Ban da thoat khoi chuc nang quan ly sinh vien\n");
                        break;                        
                
                        default:
                            printf("Ban da nhap sai. Vui long nhap lai.\n");
                        break;
                    }
                } while (chonQuanLySinhVien != 0);
            
            
            case 2:
            //  quan li diem
                do {
                    printf("===== MENU QUAN LY DIEM =====\n");
                    printf("1. Hien thi diem sinh vien\n");
                    printf("2. Nhap diem cho sinh vien\n");
                    printf("3. Cap nhap diem cho sinhvien\n");                 
                    printf("4. Diem tbc ");
                    printf("5. Sap xep theo diem tbc");
                    
                    printf("0. Thoat\n");
                    printf("Moi nhap vao lua chon cua ban: ");
                    scanf("%d", &chonQuanLyDiem);

                    switch (chonQuanLyDiem) {
                        case 0:
                            printf("Ban da thoat khoi chuc nang quan ly diem\n");
                            break;

                        case 1:
                            HienThiDanhSachSV(ArrSinhVien, slgSV);
                            HienThiDiem(ArrSinhVien, slgSV);
                            break;

                        case 2:
                            NhapDiem(ArrSinhVien, slgSV);
                            break;
                        case 3:
                        	printf("Nhap vao ma sinh vien can cap nhat: ");
                            scanf("%d", &ma);
                        	capNhatDiem(ArrSinhVien, slgSV, ma);
                        	
                        	break;
                        case 4:
                         TongTBC(ArrSinhVien, slgSV);
						 TbcMaxMin(ArrSinhVien, slgSV);
                        	
                        	break;
                        case 5:
                        	SapXepTheoDiemTB(ArrSinhVien, slgSV);
                        	  HienThiDiem( ArrSinhVien, slgSV);
                        	break;

                        default:
                            printf("Ban da nhap sai. Vui long nhap lai.\n");
                        break;    
                    }
                } while (chonQuanLyDiem != 0);
        }
    }while(chon != 3 );
	return 0;    
}

