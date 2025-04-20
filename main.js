const { app, BrowserWindow } = require('electron');

app.whenReady().then(() => {
  const win = new BrowserWindow({ width: 950, height: 800 });
  win.loadFile('index.html');
});
