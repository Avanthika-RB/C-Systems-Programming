typedef unsigned short bitmap16;

struct file {
    char *filename;
    bitmap16 permissions;
};

void grantPermission(int index, struct file *f);

void revokePermission(int index, struct file *f);

int checkPermission(int index, struct file *f);

void printPermissions(struct file *f);
