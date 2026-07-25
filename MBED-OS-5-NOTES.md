# Mbed OS 5 Notes

These projects are kept in the programming style used during the Mbed OS 5 era.

For archival reproducibility, pin your own local checkout to the Mbed OS 5 release
you actually used in college. The final 5.15 maintenance release was 5.15.9.

Do not commit a full `mbed-os/` copy into every project folder. Keep the repository
focused on your application code (`main.cpp`) and documentation.

Some very old examples use external community libraries (for example TextLCD or
specific X-NUCLEO middleware). Restore the exact historical dependency revision
before claiming a project has been re-tested.
