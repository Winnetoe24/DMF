import * as path from "path";
import { workspace, ExtensionContext } from "vscode";

import {
  LanguageClient,
  LanguageClientOptions,
  ServerOptions,
  StreamInfo,
  TransportKind,
  Executable
} from "vscode-languageclient/node";
import * as net from 'net';
import { execFile } from "child_process";
import * as fs from 'fs';
import { platform } from "os";
import { ChildProcess } from "node:child_process";
import * as term from "terminate";

let client: LanguageClient;
let server: ChildProcess;
let exited = false;
export function activate(context: ExtensionContext) {
  const getLspFileName = function () {
    switch (process.platform) {
      case "win32":
        return "lsp.exe"
      case "linux":
        return "lsp"
      default:
        throw new Error("No Version for your OS is bundled.")
    }
  }
  // The server is implemented in node
  const serverModule = context.asAbsolutePath(
    path.join("client", "lsp", getLspFileName())
  );
  // console.log(serverModule)
  // console.log("exists:", fs.existsSync(serverModule))
  server = execFile(serverModule + " --port 5007 --disabledLog", {
    shell: true
  }, (error, stdout, stderr) => {
    if (error) {
      throw error;
    }
    console.log(stdout);
    console.log(stderr)
  })
  server.on('exit', (exit) => {
    console.log("Server exited")
    exited = true;
  });
  // The server is a started as a separate app and listens on port 5007
  let connectionInfo = {
    port: 5007
  };
  //  const runExe = { module: serverModule, transport: TransportKind.stdio };
  //  const runExe: Executable = { command: serverModule, transport: TransportKind.stdio, options: {shell: false, detached: false } };
  const runExe: Executable = { command: serverModule, transport: TransportKind.stdio, options: { shell: false, detached: false } };


  // If the extension is launched in debug mode then the debug server options are used
  // Otherwise the run options are used
  // const serverOptions: ServerOptions = {
  //   run: runExe,
  //   debug: runExe,
  // };

  let serverOptions = () => {
    // Connect to language server via socket
    let socket = net.connect(connectionInfo);
    let result: StreamInfo = {
      writer: socket,
      reader: socket
    };
    return Promise.resolve(result);
  };
  // Options to control the language client
  const clientOptions: LanguageClientOptions = {
    // Register the server for all documents by default
    documentSelector: [{ scheme: "file", language: "dmf", pattern: "**/*.dmf" }],
    synchronize: {
      // Notify the server about file changes to '.clientrc files contained in the workspace
      fileEvents: workspace.createFileSystemWatcher("**/.clientrc"),
    },
  };

  // Create the language client and start the client.
  client = new LanguageClient(
    "dmf",
    "DMF Server",
    serverOptions,
    clientOptions
  );

  // Start the client. This will also launch the server
  client.start();
}

export async function deactivate() {

  const cleanupPromises = [];
  if (!client) {
    return undefined;
  }
  let promise = client.stop();
  cleanupPromises.push(promise)
  console.log("Stopping Server")

   cleanupPromises.push( new Promise((resolve, reject) => {
    term.default(server.pid, err => {
        if (err == null) {
          resolve(null)
        }else {
          reject(err)
        }
     })

  }));
  await Promise.all(cleanupPromises)
}
