#include <stdio.h>

int main() {
    FILE *fp = fopen("noloops.c", "w");
    
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "#include <stdio.h>\n\n");
    fprintf(fp, "int main() {\n");
    fprintf(fp, "    ");
    for (int i = 0; i <= 1000000; i++) {
        fprintf(fp, "  printf(\"%d\\n\");\n", i);
    }
    fprintf(fp, "    return 0;\n");
    fprintf(fp, "}\n");

    fclose(fp);
    printf("Generated program saved as \"counter.c\"\n");
    
    return 0;
}

