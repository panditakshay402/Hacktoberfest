import qrcode

# Input the link or text you want to convert to a QR code
link = "https://www.example.com"

# Create a QR code object
qr = qrcode.QRCode(
    version=1,
    error_correction=qrcode.constants.ERROR_CORRECT_L,
    box_size=10,
    border=4,
)

# Add the data (link or text) to the QR code
qr.add_data(link)
qr.make(fit=True)

# Create an image from the QR code data
qr_image = qr.make_image(fill_color="black", back_color="white")

# Save the QR code as an image file
qr_image.save("qrcode.png")

print(f"QR code for {link} has been saved as qrcode.png")
