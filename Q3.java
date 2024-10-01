import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

public class ExcelReader {
    public static void main(String[] args) {
        // Specify the path to the Excel file
        String excelFilePath = "example.xlsx"; // Replace with your Excel file path

        try {
            // Open the file
            FileInputStream fileInputStream = new FileInputStream(new File(excelFilePath));

            // Create a workbook instance for the Excel file
            Workbook workbook = new XSSFWorkbook(fileInputStream);

            // Access the first sheet
            Sheet sheet = workbook.getSheetAt(0);

            // Iterate through each row in the sheet
            for (Row row : sheet) {
                // Iterate through each cell in the row
                for (Cell cell : row) {
                    // Print the cell value based on its type
                    switch (cell.getCellType()) {
                        case STRING:
                            System.out.print(cell.getStringCellValue() + "\t");
                            break;
                        case NUMERIC:
                            System.out.print(cell.getNumericCellValue() + "\t");
                            break;
                        case BOOLEAN:
                            System.out.print(cell.getBooleanCellValue() + "\t");
                            break;
                        case FORMULA:
                            System.out.print(cell.getCellFormula() + "\t");
                            break;
                        default:
                            System.out.print("UNKNOWN\t");
                            break;
                    }
                }
                System.out.println();
            }

            // Close the workbook and file input stream
            workbook.close();
            fileInputStream.close();

        } catch (IOException e) {
            System.out.println("Error reading the Excel file: " + e.getMessage());
            e.printStackTrace();
        }
    }
}