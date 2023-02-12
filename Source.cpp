#include <windows.h>

TCHAR szClassName[] = TEXT("Window");

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		RECT rect = { 0,0,100,100 };
		HDC hdc = CreateMetaFile(TEXT("metafile.wmf"));
		for (int i = 0; i < 1204702; ++i) // 1204703ÇæÇ∆ÇæÇﬂ
		{
			FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		}
		HMETAFILE hMetaFile = CloseMetaFile(hdc);
		HANDLE hHandle = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, sizeof(METAFILEPICT));
		METAFILEPICT *pMetaFilePict = (METAFILEPICT *)GlobalLock(hHandle);
		pMetaFilePict->mm = MM_TEXT;
		pMetaFilePict->xExt = 100;
		pMetaFilePict->yExt = 100;
		pMetaFilePict->hMF = hMetaFile;
		GlobalUnlock(hHandle);
		OpenClipboard(NULL);
		EmptyClipboard();
		MessageBox(0, SetClipboardData(CF_METAFILEPICT, pMetaFilePict) ? TEXT("ê¨å˜") : TEXT("é∏îs"), 0, 0);
		CloseClipboard();
		DeleteMetaFile(hMetaFile);
	}
	break;
	case WM_RBUTTONDOWN:
	{
		RECT rect = { 0,0,100,100 };
		HDC hdc = CreateEnhMetaFile(NULL, TEXT("enhmetafile.emf"), &rect, NULL);
		for (int i = 0; i < 330321; ++i) // 330322ÇæÇ∆ÇæÇﬂ
		{
			FillRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		}
		HENHMETAFILE hEnhMetaFile = CloseEnhMetaFile(hdc);
		OpenClipboard(NULL);
		EmptyClipboard();
		MessageBox(0, SetClipboardData(CF_ENHMETAFILE, hEnhMetaFile) ? TEXT("ê¨å˜") : TEXT("é∏îs"), 0, 0);
		CloseClipboard();
		DeleteEnhMetaFile(hEnhMetaFile);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR pCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wndclass = {
		CS_HREDRAW | CS_VREDRAW,
		WndProc,
		0,
		0,
		hInstance,
		0,
		LoadCursor(0,IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		0,
		szClassName
	};
	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(
		szClassName,
		TEXT("Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		0,
		0,
		hInstance,
		0
		);
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
