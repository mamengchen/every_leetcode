//面试29:二叉树的镜像
//从头到根先序遍历，每遍历到一个节点让这个节点
//的左右节点，左右交换

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
}

void MirrorRecursively(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
    {
        return;
    }
    if (pNode->m_pLeft == nullptr && pNode->m_pRight == nullptr)
    {
        return;
    }
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pLeft;
    pNode->m_pRight = pTemp;
    if (pNode->m_pLeft)
    {
        MirrorRecursively(pNode->m_pLeft);
    }
    if (pNode->m_pRight)
    {
        MirrorRecursively(pNode->m_pRight);
    }
}
