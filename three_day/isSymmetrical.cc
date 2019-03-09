//面试题28:对称的二叉树
//对于对称的二叉树，它们的前序遍历的序列和对称的前序遍历是一样的
//但是这里需要注意一些全部节点都是一样的数的对称
//二叉树，所以我们应该也要把nullptr节点加上

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if (pRoot1 == nullptr && pRoot2 == nullptr)
    {
        return true;
    }

    if (pRoot1 == nullptr || pRoot2 == nullptr)
    {
        return false;
    }

    if (pRoot1->m_nValue != pRoot2->m_nValue)
    {
        return false;
    }

    return isSymmetrical(pRoot1->m_pLeft, pRoot2->m_pRight)&&
        isSymmetrical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
