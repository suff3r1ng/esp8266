// Function to generate QR code
function generateQRCode() {
  const data = document.getElementById('dataInput').value;
  const qrcodeContainer = document.getElementById('qrcode');
  
  // Clear the QR Code container to avoid drawing multiple QR codes
  qrcodeContainer.innerHTML = '';
  
  // Generate the QR Code using the data from the input field
  if (data) {
    new QRCode(qrcodeContainer, data);
  } else {
    alert('Please enter some data to convert to QR code.');
  }
}

// Existing functions for QR scanner initialization and handling
function onScanSuccess(decodedText, decodedResult) {
    // ... existing code ...
}

function onScanFailure(error) {
    // ... existing code ...
}

let html5QrcodeScanner = new Html5QrcodeScanner("reader", { fps: 10, qrbox: 250 });
html5QrcodeScanner.render(onScanSuccess, onScanFailure);