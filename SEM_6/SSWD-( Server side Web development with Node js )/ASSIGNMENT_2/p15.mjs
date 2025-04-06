import os from 'os';

const osDetails = {
    platform: os.platform(),
    architecture: os.arch(),
    cpuCores: os.cpus().length,
    totalMemory: `${(os.totalmem() / (1024 ** 3)).toFixed(2)} GB`,
    freeMemory: `${(os.freemem() / (1024 ** 3)).toFixed(2)} GB`,
    uptime: `${(os.uptime() / 3600).toFixed(2)} hours`,
    hostname: os.hostname(),
    osType: os.type(),
    release: os.release(),
};

console.log("Operating System Details:");
console.log(osDetails);

/*
Operating System Details:
{
  platform: 'win32',
  architecture: 'x64',
  cpuCores: 16,
  totalMemory: '23.70 GB',
  freeMemory: '12.09 GB',
  uptime: '23.82 hours',
  hostname: 'LAPTOP-GLVQMALP',
  osType: 'Windows_NT',
  release: '10.0.26100'
}
*/